#include "user.h"
#include <iostream>
using namespace std;
User::User()
{
    //Empty user
    this->id = 0;
    this->name = "";
    this->city = "";
    this->age = 0;
    nUsers++;
}

User::User(int id, std::string name, std::string city, int age, std::vector<Friend> friends)
{
    this->id = id;
    this->name = name;
    this->city = city;
    this->age = age;
    this->friends = friends;
    nUsers++;
}

string User::GetName()
{
    return name;
}

int User::GetID()
{
    return id;
}

string  User::GetCity()
{
    return city;
}

int User::GetAge()
{
    return age;
}

vector<Friend>  User::GetFriends()
{
    return friends;
}