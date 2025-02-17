#ifndef cities_h  
#define cities_h  
#include <string>
#include <vector>
#include <map>
#include "city.h"
using namespace std;
class Cities
{
public:
    Cities();
    void LoadCities(vector<string> data);
    string MostPopularHobby();
    string MostPopularFirstName();
    json CityAverages();

private:
    map<string, City> cities;
};

#endif