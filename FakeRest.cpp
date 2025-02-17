#include <iostream>
#include <nlohmann/json.hpp> 

#include "client.h"

#include "cities.h"

using json = nlohmann::json;
using namespace std; // I got tired of the extra typing.


//Example Data 
// {"name":"Noah","city":"Boston","age":97,"friends":[{"name":"Oliver","hobbies":["Watching Sports","Skiing & Snowboarding",
//     "Collecting"]},{"name":"Olivia","hobbies":["Running","Music","Woodworking"]},{"name":"Robert","hobbies":["Woodworking","Calligr
//     aphy","Genealogy"]},{"name":"Ava","hobbies":["Walking","Church Activities"]},{"name":"Michael","hobbies":["Music","Church Activ
//     ities"]},{"name":"Michael","hobbies":["Martial Arts","Painting","Jewelry Making"]}]}
                
int main(int argc, char* argv[]) {
    // Check if the user has provided a URL argument
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <URL>" << std::endl;
        return 1; // Exit with an error code if no URL is provided
    }

    // The URL is provided as the second argument (argv[1])
    std::string url = argv[1];

    Client client(url);
    vector<string> users = client.Get();

    Cities cities;
    cities.LoadCities(users);
    auto j = cities.CityAverages();
    cout << j.dump(4) << endl;
    // for (auto& element : j.items()) {
    //     std::cout << "Key: " << element.key() << endl;
    //     for (auto &e: element.value().items())
    //     {
    //         cout << "\t" << e.key() << std::endl;
    //         for (auto &a: e.value().items())
    //         {
    //             cout << "\t\t" << a.key() << ": " << a.value() << std::endl;
    //         }
    //     }
    // }
    return 0;
}