#include "client.h"

#include <stdlib.h> /* for realloc */
#include <string.h> /* for memcpy */
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;
struct memory {
    char *response;
    size_t size;
};

//Callback for curl
static size_t cb(char *data, size_t size, size_t nmemb, void *clientp)
{
    size_t realsize = size * nmemb;
    struct memory *mem = (struct memory *)clientp;

    char *ptr = (char *)realloc((void *)mem->response, mem->size + realsize + 1);
    if(!ptr)
    {
        return 0;  /* out of memory */
    }

    mem->response = ptr;
    memcpy(&(mem->response[mem->size]), data, realsize);
    mem->size += realsize;
    mem->response[mem->size] = 0;
    return realsize;
}
   
vector<string> Client::SplitIntoLines(const string& str) 
{
    vector<string> lines;
    string line;
    istringstream stream(str);

    // Read each line from the stream and push it to the vector
    while (getline(stream, line)) 
    {
        lines.push_back(line);
    }

    return lines;
}

Client::Client(std::string url)
{
    curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, cb);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA,  (void *)&chunk);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT_MS, 30 * 1000L );
    }

}
Client::~Client()
{
    // free the buffer 
    free(chunk.response);
    // Clean up curl
    curl_easy_cleanup(curl);

}

vector<string> Client::Get()
{
    vector<string> items;
    if (curl)
    {
        CURLcode result = curl_easy_perform(curl);
        if (result == CURLE_OK)
        {
            if (chunk.size > 0)
            {
                items = SplitIntoLines(chunk.response);
            }
        }
    }
    return items;
}