// CPP program for implementation of QuickSelect 
#include <bits/stdc++.h> 
#include "covid19_data.hpp"
using namespace std; 
  
int partition(int arr[], Covid19Data arr_data[], int l, int r)
{
    int x = arr[r], i = l;
    for (int j = l; j <= r-1; ++j)
    {
        if (arr[j] <= x)
        {
            swap(arr[i], arr[j]);
            swap(arr_data[i], arr_data[j]);

            i++;
        }
    }
    swap(arr[i], arr[r]);
    swap(arr_data[i], arr_data[r]);
    return i;
}    
    
int kth_biggest(int arr[], Covid19Data arr_data[], int l, int r, int k)
{
        
    if (k < 0 || k > r-l+1) {return -1;}

    //partition the array (similar to quicksort)
    int index = partition(arr, arr_data, l, r);
        
     //if position same as k return rank-k element
    if (index - l == k - 1)
        return index;

    //if rank-k element is less, look in left sub-array
    if (index - l > k - 1)
        return kth_biggest(arr, arr_data, l, index - 1, k);
    else //look in right sub-array
        return kth_biggest(arr, arr_data, index + 1, r, k - index + l - 1);
} 

    

