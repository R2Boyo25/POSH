#pragma once

#include "../parse/parse.hpp"
#include <vector>
#include <string>
#include <map>
#include <stdexcept>

namespace com {
    class Command {
        public:
            Command();
            Command(void (*func)(int, std::vector<std::string>), std::string com_name);
            void run(std::vector<std::string> arguments);
            std::string name;
        private:
            void (*command_function)(int, std::vector<std::string>);
    };

    class Commands {
        public:
            Commands();
            void addCommand(Command command);
            void run(std::string arg_string);
        private:
            std::map<std::string, Command> command_list;
    };
}