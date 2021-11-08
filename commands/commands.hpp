#pragma once

#include <string>
#include <vector>
#include <filesystem>
#include <iostream>

//extern std::filesystem::path path;

namespace commands {
    void ls(int argc, std::vector<std::string> argv);
    void cd(int argc, std::vector<std::string> argv);
    void cp(int argc, std::vector<std::string> argv);
    void mv(int argc, std::vector<std::string> argv);
    void rm(int argc, std::vector<std::string> argv);
    void ec(int argc, std::vector<std::string> argv);
    void run(int argc, std::vector<std::string> argv);
}