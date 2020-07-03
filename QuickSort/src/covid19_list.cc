#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <locale>

#include "quicksort.hpp"
#include "covid19_data.hpp"
#include "covid19_data.cc"

using namespace std;

void print_usage(const char *prog_name)
{
        cerr << "Usage: " << prog_name << " <data-filename> [options]" << endl;
        cerr << "Options:" << endl;
        cerr << "  --deaths  :  sort new deaths data" << endl;
        cerr << "  --by-total  :  sort total cases data" << endl;
        cerr << "  --by-total --by-deaths  : sort total deaths data" << endl;
        cerr << "  -n N : ( example -n 20 )  display top N items instead of 10" << endl;

}

// This program reads the covid19 data from a CSV (Comma
// Separated Values) file. It sorts and prints the covid19 datas by the number of new cases | new deaths | total cases | total deaths in descending order by default. You may pass command line
// options to choose a specific order type.
int main(int argc, char** argv)
{
        // We require at least a single command line argument
        if (argc < 2) {
                print_usage(argv[0]);
                return EXIT_FAILURE;
        }

        // By default sort in descending order. Parse command line options and
        // sort according to given type
        bool sort_descending = true;
        string data_type = "new_cases";
        int number = 10;
        for (int i = 2; i < argc; ++i) 
        {

                if ((strcmp(argv[i], "--by-total") == 0))
                {
                        if(argv[i+1] != NULL && strcmp(argv[i+1], "--by-deaths") == 0)
                        {
                                data_type = "total_deaths";
                        }

                        else
                        {
                                data_type = "total_cases";
                        }
                        
                        
                }


                else if ((strcmp(argv[i], "--by-deaths") == 0) && (strcmp(argv[i-1], "--by-total") == 1))
                {
                       data_type = "new_deaths";
                }

                if (strcmp(argv[argc-2], "-n") == 0) 
                {
                        if(atoi(argv[argc-1])>=1)
                        {
                                number = atoi(argv[argc-1]);
                        }
                        else
                        {
                                return EXIT_FAILURE;
                        }
                        
                        
                }
                

                
        }

        // Load covid19 data and year data from the CSV file.
        vector<Covid19Data> covid19_data;
        string date_data;
        string location_data;
        int new_cases_data;
        int new_deaths_data;
        int total_cases_data;
        int total_deaths_data;
        load_covid19_data(covid19_data, date_data,location_data,new_cases_data, new_deaths_data,total_cases_data,total_deaths_data, argv[1]);
        
        // Sort the data using a Covid19DataCmp object for comparisons according to given comparison type ( data_type ) . 
        quicksort_generic(covid19_data, Covid19DataCmp(data_type));

        // Output
        cout <<"------------------"<< endl;
        cout <<"------------------"<< endl;
        cout <<"Quick Sort : "<< endl;
        cout << "Date " << "          " << "New Cases " <<"          "<< "New Deaths " << "          "<< "Total Cases "<< "          " << "Total Deaths " << "          " << "Location" << endl;
       
        for (int i = 0; i<number;i++) 
        {
                cout << covid19_data[i].date << "     "  << covid19_data[i].new_cases<< "               "  << covid19_data[i].new_deaths << "                 " << covid19_data[i].total_cases << "                 " << covid19_data[i].total_deaths << "                   " << covid19_data[i].location << endl;
        }


        return EXIT_SUCCESS;
}
