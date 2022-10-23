#ifndef CPP_PRACTICE_SRC_CPR_H
#define CPP_PRACTICE_SRC_CPR_H

#include <iostream>

#include "nlohmann/json.hpp"

using json = nlohmann::json;

json GetJson(std::string &url);

void TestCpr();

#endif