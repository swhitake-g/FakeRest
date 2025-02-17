#include "cities.h"
#include <string>
#include <nlohmann/json.hpp> 
using json = nlohmann::json;
using namespace std;
Cities::Cities()
{

};


void Cities::LoadCities(vector<string> items)
{
    for (auto i:items)
    {
        // Parse the string into a JSON object
        try
        {
            json j = json::parse(i);

            User u;
            u.from_json(j);

            string cityName = u.GetCity();
            auto it = cities.find(cityName);
            if (it != cities.end())
            {
                it->second.AddUser(u);
    
            }
            else
            {
                City city(cityName);
                city.AddUser(u);
                cities[cityName] = city;
            }
            
        }
        catch (const exception& e)
        {
            // print the exception

            cout << "Exception " << e.what() <<  " parsing: " << i << endl;
        } 
    }
}

string Cities::MostPopularHobby()
{
    map<string,int> popularHobbies;
    for (auto c: cities)
    {
        vector<string> hobbiesList = c.second.GetHobbies();
        for (auto hobbie: hobbiesList)
        {
            auto it = popularHobbies.find(hobbie);
            if (it == popularHobbies.end())
            {
                popularHobbies[hobbie] = 1;
            }
            else
            {
                it->second++;
            }
        }
    }
    int currentMax = 0;
    string mostPopularHobby = "";
    for (auto it = popularHobbies.cbegin(); it != popularHobbies.cend(); ++it ) 
    {
        if (it->second > currentMax) 
        {
            mostPopularHobby = it->first;
            currentMax = it->second;
        }
    }  
    return mostPopularHobby;
}

string Cities::MostPopularFirstName()
{
    map<string,int> firstNames;

    for (auto c: cities)
    {
        vector<string> firstNameList = c.second.GetFirsNames();
        for (auto name: firstNameList)
        {
            auto it = firstNames.find(name);
            if (it == firstNames.end())
            {
                firstNames[name] = 1;
            }
            else
            {
                it->second++;
            }
        }
    }  
    int currentMax = 0;
    string mostPopularFirstName = "";
    for (auto it = firstNames.cbegin(); it != firstNames.cend(); ++it ) 
    {
        if (it->second > currentMax) 
        {
            mostPopularFirstName = it->first;
            currentMax = it->second;
        }
    }  
    return mostPopularFirstName;
}

json Cities::CityAverages()
{

    //std::map<std::string, nlohmann::json> objectMap;
    typedef  std::map<std::string, nlohmann::json> objectMapType;
    objectMapType objectMap;
    std::map<string, objectMapType> cityMap;

    for (auto c: cities)
    {
        std::map<std::string, string> parameters;
        City city = c.second;
        parameters["AverageAge"] = to_string(c.second.AverageAgeOfUsers());
        parameters["AverageFriends"] = to_string(c.second.AverageNumberOfFriends());
        parameters["MostFriends"] = c.second.MostFriends().GetName();
        // Convert the map to a JSON object
        nlohmann::json jsonObject = parameters;
        objectMap[c.first] = jsonObject;
    }
    cityMap["Cities"] = objectMap;

    std::map<std::string, std::string> parameters;

    parameters["MpstCommonFirstName"] =  MostPopularFirstName();
    parameters["MostCommonHobby"] =  MostPopularHobby();   
    nlohmann::json jsonObject = parameters;
    cityMap["MostCommonInAllCities"] = jsonObject;

    return nlohmann::json(cityMap);


}