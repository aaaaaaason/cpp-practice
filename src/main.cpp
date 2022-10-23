#include <iostream>
#include <chrono>

#include "fmt/format.h"
#include "nlohmann/json.hpp"
using json = nlohmann::json;
#include "absl/flags/flag.h"
#include "absl/flags/parse.h"
#include "absl/flags/usage.h"

#include "filesystem.hpp"
#include "json.hpp"
#include "abstract.hpp"
#include "cpr.hpp"

ABSL_FLAG(bool, bool_type, false, "a bool option");
ABSL_FLAG(std::string, string_type, "", "a string option");

void TestAbseilFlags(int argc, char **argv)
{
    // This should be called before ParseCommandLine.
    absl::SetProgramUsageMessage("For practicing CPP");

    absl::ParseCommandLine(argc, argv);

    std::cout << "bool_type: " << absl::GetFlag(FLAGS_bool_type) << std::endl;
    std::cout << "string_type: " << absl::GetFlag(FLAGS_string_type) << std::endl;
}

int main(int argc, char **argv)
{
    TestAbseilFlags(argc, argv);

    // ListEntries();

    // TestAbstract();

    // TestCpr();
}