#ifndef CPP_PRACTICE_SRC_JSON_H
#define CPP_PRACTICE_SRC_JSON_H

#include <iostream>

#include "fmt/format.h"
#include "nlohmann/json.hpp"
using json = nlohmann::json;

template <class T>
void toJSON(T &t)
{
    json j = t;
    fmt::print("{}\n", j.dump());
}

struct A
{
    int a;
    int b;
    std::string c;
};

void to_json(json &j, const A &o);
void from_json(const json &j, A &o);

#endif