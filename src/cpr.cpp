#include "cpr.hpp"

#include <iostream>

#include "nlohmann/json.hpp"
#include "cpr/cpr.h"

using json = nlohmann::json;

json GetJson(std::string &url)
{
    cpr::Response r = cpr::Get(cpr::Url{url});

    std::cout << r.text << std::endl;

    return json::parse(r.text);
}

void TestCpr()
{
    std::string url("https://hacker-news.firebaseio.com/v0/item/8863.json?print=pretty");
    GetJson(url);
}