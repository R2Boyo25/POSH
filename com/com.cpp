#include "com.hpp"

namespace com {
    Command::Command(void (*func)(int, std::vector<std::string>), std::string com_name) {
        name = com_name;
        command_function = func;
    }

    Command::Command(){

    }

    void Command::run(std::vector<std::string> argv) {
        int argc = argv.size();
        (*command_function)(argc, argv);
    }

    Commands::Commands() {
        
    }

    void Commands::addCommand(Command command) {
        command_list[command.name] = command;
    }

    void Commands::run(std::string arg_string) {
        std::vector<std::string> args = argparse::parseArgs(arg_string);
        if (args.size() == 0) {
            args = {""};
        }
        std::string command = args[0];
        //args.erase( args.begin() ); 
        if (command_list.find(command) != command_list.end()){
            command_list[command].run(args);
        } else if (command_list.find("_default") != command_list.end()) {
            command_list["_default"].run(args);
        } else {
            throw std::invalid_argument( command + " not found and no default command" );
        }

    }
}