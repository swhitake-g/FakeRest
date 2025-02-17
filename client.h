#ifndef client_h  
#define client_h  
#include <string>
#include <vector>
#include <curl/curl.h>
using namespace std;
// We do not need anything fancy since we just want to response to work with.
class Client
{

    struct memory {
        char *response;
        size_t size;
    };
private:
    vector<string> SplitIntoLines(const string& str);

public:
    Client(string url);
    ~Client();
    vector<string> Get();

private:
    CURL *curl;
    struct memory chunk = {0};
};
#endif