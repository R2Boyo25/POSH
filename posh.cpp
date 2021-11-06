/*
Pine's OK shell
*/
#include <string.h>
#include <iostream>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;
fs::path path = "/home/";
const float version = 1;

#include "command.h"

int main()
{
	cout << "Pine's OK Shell, POSH, v" << version << "\n";
	string cmd;
	while(1)
	{
		cout << string(path) << " > ";
		getline( cin, cmd );
		if(cmd == "help") cout << "Pine Command Interpreter\nCommands: help, ls\n";
		else if(cmd.find("ls") == 0)
			ls();
		else if(cmd.find("cd") == 0)
		{
			if (cmd.length() >= 4)
				cd(cmd);
		}
		else if(cmd.find("cp") == 0)
		{
			if (cmd.length() >= 4)
				cp(cmd);
		}
		else if(cmd.find("mv") == 0)
		{
			if (cmd.length() >= 4)
				mv(cmd);
		}
		else if(cmd.find("rm") == 0)
		{
			if (cmd.length() >= 4)
				rm(cmd);
		}
		else if(cmd.find("ec") == 0)
			ec(cmd);
		else
		{
			cout << "Error: no command \"" << cmd << "\"\n";
		}
	}
}