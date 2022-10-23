#include "json.hpp"

#include <iostream>

#include "nlohmann/json.hpp"

using json = nlohmann::json;

void to_json(json &j, const A &o)
{
    j = json{{"a", o.a}, {"b", o.b}, {"c", o.c}};
}

void from_json(const json &j, A &o)
{
    j.at("a").get_to(o.a);
    j.at("b").get_to(o.b);
    j.at("c").get_to(o.c);
}

void TestJson()
{
    A tmp{1, 2, "a custom object"};
    toJSON(tmp);
}