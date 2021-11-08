/*
TODO:
Run external apps
Make a remotely better command parser
Clean the code
*/
#include <iostream>
#include <filesystem>
using namespace std;
filesystem::path path = "/home/";
const string version = "pre-alpha";

#include "posh.h"

int main()
{
	cout << "Pine's OK Shell (POSH) version " << version << "\n";
	string cmd;
	while(1)
	{
		cout << string(path) << " > ";
		getline( cin, cmd );
		if(cmd == "version") cout << "POSH version " << version << "\nhttps://github.com/Boops-Boops/POSH\n";
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
		{
			if(cmd.length() > 2)
				ec(cmd);
		}
		else if(cmd.find("./") == 0)
		{
			if(filesystem::is_regular_file(cmd.substr(2, cmd.find(' ', 2)))) cout << "POSH can't run programs right now\nIf you know how and want to help, start a pull request at https://github.com/Boops-Boops/POSH\n";
		}
		else
		{
			cout << "Error: no command \"" << cmd << "\"\n";
		}
	}
}