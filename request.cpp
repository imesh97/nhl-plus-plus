/*
CS3307 INDIVIDUAL ASSIGNMENT (request.cpp)
Request class for web API processing

by: Imesh Nimsitha
2023/02/07
*/

#include "request.h"

using json = nlohmann::json;

/*
CONSTRUCTOR: Request
Initializes Request object with default values and fetch url
@param Fetch URL (string)
@return None
*/
Request::Request(std::string url)
{
    this->url = url;                        // set fetch url
    this->chunk.memory = (char *)malloc(1); // default values for chunk
    this->chunk.size = 0;
};

/*
DESTRUCTOR: Request
Destroy dynamic memory for Request object
@param None
@return None
*/
Request::~Request()
{
    free(chunk.memory); // free chunk's dynamic memory
};

/*
FUNCTION: Execute request
Execute a web API request
@param None
@return true if successful request, false if error (bool)
*/
bool Request::execute()
{
	CURL *curl_handle;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_ALL); // initialize curl request
    curl_handle = curl_easy_init();
    curl_easy_setopt(curl_handle, CURLOPT_URL, url.c_str()); // set options such as url and callback function
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, Request::WriteMemoryCallback);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&chunk);
    curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");

    res = curl_easy_perform(curl_handle); // perform curl request
    
    curl_easy_cleanup(curl_handle); // finish using curl (clean up)
    curl_global_cleanup();

    return (res == CURLE_OK); // return curl request state
};

/*
FUNCTION: Request result
Get request data in a string format
@param None
@return Serialized JSON data (string)
*/
std::string Request::result()
{
    std::string data(this->chunk.memory);
    return data;
};

/*
FUNCTION: Parse result
Get vector of Game objects from parsed JSON data
@param None
@return Series of Game objects (vector)
*/
std::vector<Game> Request::parse()
{
    std::vector<Game> games;        // vector for storing game objects
    json j = json::parse(result()); // parse json from data string

    if (!j.contains("dates"))
    { // exit if json data does not exist
        std::cerr << "ERROR: Cannot parse JSON data." << std::endl;
        exit(1);
    };

    for (auto it = j["dates"].begin(); it != j["dates"].end(); ++it)
    { // iterate through all dates
        for (auto jt = it.value()["games"].begin(); jt != it.value()["games"].end(); ++jt)
        { // iterate through all games for each date
            if (jt.value()["status"]["detailedState"] == "Final")
            {              // filter for only games that have been played
                Game game; // initialize game object

                game.setHomeTeam(jt.value()["teams"]["home"]["team"]["name"]); // set game values from the parsed json
                game.setAwayTeam(jt.value()["teams"]["away"]["team"]["name"]);
                game.setHomeScore(jt.value()["teams"]["home"]["score"]);
                game.setAwayScore(jt.value()["teams"]["away"]["score"]);

                games.push_back(game); // insert into games vector
            };
        };
    };

    return games;
};

/*
FUNCTION: Callback
Static write memory callback function for curl request
@param contents (void *), size (size_t), nmemb (size_t), userp (void *)
@return Memory callback size (size_t)
*/
size_t Request::WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    size_t realsize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *)userp;

    char *ptr = (char *)realloc(mem->memory, mem->size + realsize + 1);
    if (!ptr)
    { // error in realloc()
        std::cerr << "ERROR: Not enough memory." << std::endl;
        return 0;
    };

    mem->memory = ptr;
    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;

    return realsize;
};
