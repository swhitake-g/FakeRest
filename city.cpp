#include "city.h"

#include <iostream>
using namespace std;

City::City()
{
    this->name = "";
};


City::City(string name)
{
    this->name = name;
};
 
void City::AddUser(User &user)
{
    int id = user.GetID(); 
    auto it = users.find(id);
    if (it == users.end())
    {
        users[id] =  user;
        // cout << "num users " << this->users.size() << " in " << name << endl;
        // for (auto i : users)
        //     cout << i.first << ": " << i.second.GetName() << '\n';
    }
    else
    {
        cout << "Duplicate User ID " << id << endl;
    }
}

int City::NumUsers()
{
    return users.size();
}

float City::AverageAgeOfUsers() 
{ 
    float avgAge = 0.0;
    for (auto u: users)
    {
        avgAge += u.second.GetAge();
    }
    return avgAge/(float)users.size();
};

float City::AverageNumberOfFriends() 
{ 
    float avgNumFriends = 0.0;
    for (auto u: users)
    {
        avgNumFriends += u.second.GetFriends().size();
    }
    return avgNumFriends/(float)users.size();

};
User City::MostFriends() 
{
    int maxFriends = 0;
    User userWithMostFriends;
    for (auto u: users)
    {
        int numFriends = u.second.GetFriends().size();
        if (numFriends > maxFriends)
        {
            maxFriends = numFriends;
            userWithMostFriends = u.second;
        }
    }
    return userWithMostFriends;

};


vector<string> City::GetFirsNames()
 { 
    vector<string> names;
    for (auto u: users)
    {
        names.push_back(u.second.GetName());
    }
    return names;
};

vector<string> City::GetHobbies()
{
    vector<string> hobbies;
    for (auto u: users)
    {
        auto friends = u.second.GetFriends();
        for (auto f: friends)
        {
            for (auto h: f.GetHobbies())
            {
                hobbies.push_back(h);
            }
        }
    }
    return hobbies;
}
