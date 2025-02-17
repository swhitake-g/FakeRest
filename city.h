#ifndef city_h  
#define city_h  
#include "user.h"
#include <string>
#include <vector>
#include <curl/curl.h>
#include <map>
#include <iostream>
using namespace std;
// We do not need anything fancy since we just want to response to work with.
class City
{
public:
    City();
    City(string name);
    int NumUsers();
    void AddUser(User &user);
    float AverageAgeOfUsers();
    float AverageNumberOfFriends();
    User MostFriends();
    vector<string> GetFirsNames();
    vector<string> GetHobbies();



    // Implementing a deep copy constructor
    City(const City& other)
        : name(other.name)
    {
        for (auto u: other.users)
        { 
            users[u.first] = u.second;
        }
    }

    // Implementing the copy assignment operator for deep
    // copying
    City& operator=(const City& other)
    {
        if (this != &other) { // Prevent self-assignment
            name = other.name;
            users = other.users;
            //for (auto u: other.users)
            // { 
            //     users[u.first] = u.second;
            // }
        }
        return *this;
    }

private:
    string name;
    map<int, User> users;
};

#endif