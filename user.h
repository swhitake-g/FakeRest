#ifndef user_h  
#define user_h  
#include "friend.h"
#include <nlohmann/json.hpp> 
using json = nlohmann::json;
#include <string>
using namespace std;
static int nUsers = 0;

class User
{
public:
    User();
    User(int id, std::string name, std::string city, int age, std::vector<Friend> friends);
    string GetName();
    int GetID();
    string GetCity();
    int GetAge();
    vector<Friend> GetFriends();
    // Implementing a deep copy constructor
    User(const User& other)
        : name(other.name)
    {
        name = other.name;
        id = other.id;
        city = other.city;
        age = other.age;
        friends = other.friends;
    }

    // Implementing the copy assignment operator for deep
    // copying
    User& operator=(const User& other)
    {
        if (this != &other) { // Prevent self-assignment
            name = other.name;
            id = other.id;
            city = other.city;
            age = other.age;
            friends = other.friends;
        }
        return *this;
    }


    void from_json(const json& j, std::vector<Friend>& friends) {
        for (const auto& item : j) {
            Friend f;
            f.from_json(item);  
            friends.push_back(f);  
        }
    }
    void from_json(const json& j) {
        //Occasionally there is no id so use a counter
        if (j.contains("id"))
            j.at("id").get_to(id);  
        else
            id = nUsers++;
        j.at("name").get_to(name);
        j.at("city").get_to(city);
        j.at("age").get_to(age);
        from_json(j.at("friends"), friends);
    }
private:
    //"id":600000,"name":"Noah","city":"Charleston","age":45,"friends"
    int id;
    std::string name;
    std::string city;
    int age;
    std::vector<Friend> friends;
};
#endif

