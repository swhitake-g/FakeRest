#ifndef friend_h  
#define friend_h  
#include <string>
#include <vector>
#include <nlohmann/json.hpp> 
using json = nlohmann::json;
using namespace std;
class Friend
{
public:
    Friend() {};
    Friend(string name, vector<string> hobbyList);
    vector<string> GetHobbies();
    // Implementing a deep copy constructor
    Friend(const Friend& other)
        : name(other.name)
    {
        name = other.name;
        hobbies = other.hobbies;
    }

    // Implementing the copy assignment operator for deep
    // copying
    Friend& operator=(const Friend& other)
    {
        if (this != &other) { // Prevent self-assignment
            name = other.name;
            hobbies = other.hobbies;
        }
        return *this;
    }
    void from_json(const json& j) {
        j.at("name").get_to(name);  // Use `at` to access by key
        j.at("hobbies").get_to(hobbies);
    }
private:
    string name;
    vector<string> hobbies;
};
#endif