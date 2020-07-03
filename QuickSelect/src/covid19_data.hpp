#ifndef POPULATION_DATA_HPP
#define POPULATION_DATA_HPP

#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Structure to store date, location , new cases , new deaths , total cases , total deaths
struct Covid19Data {
        string date;
        string location;
        int new_cases;
        int new_deaths;
        int total_cases;
        int total_deaths;
};

// A class to compare to Covid19DataCmp object. The constructor takes parameters
// to customize sorting. bool descending determines the order (ascending,descending)
class Covid19DataCmp
{
public:
        Covid19DataCmp(string type)
        {
                m_type = type;
        }

        

        bool operator()(const Covid19Data& pd0, const Covid19Data& pd1) const
        {     
                
                if (!m_type.compare("new_cases"))
                {
                         return pd0.new_cases> pd1.new_cases;
                }

                else if (!m_type.compare("new_deaths"))
                {
                        return pd0.new_deaths > pd1.new_deaths;
                }
                
                else if (!m_type.compare("total_cases"))
                {
                        return pd0.total_cases > pd1.total_cases;
                }

                else if (!m_type.compare("total_deaths"))
                {
                        return pd0.total_deaths > pd1.total_deaths;
                }

                else
                {
                        return false;
                }
                       
        }



         
private:
        // private data fields are initialize during construction. They specify
        // how to compare to Covid19Data objects.
        string m_type; // type describes the compare type.
         
};



// Function to load Covid19Data from a CSV file.
void load_covid19_data(vector<Covid19Data> &Covid19_Data,
                          string &date_data, string &location_data, int &new_cases_data, int &new_deaths_data, int &total_cases_data, int &total_deaths_data,
                          const std::string &filename);

#endif
