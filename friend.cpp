#include "friend.h"

Friend::Friend(std::string name, std::vector<std::string> hobbyList)
{    
    name = name;
    hobbies = hobbyList;
}

vector<string> Friend::GetHobbies()
{
   return hobbies;
}