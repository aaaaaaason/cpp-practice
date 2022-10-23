#include "filesystem.hpp"

#include <iostream>
#include <filesystem>

#include <fmt/format.h>

namespace fs = std::filesystem;

void ListEntries(const std::string &name)
{
    fs::path path(name);

    fs::directory_iterator di(path);

    for (auto &de : di)
    {
        fmt::print("{}\n", de.path().generic_string());
    }
}