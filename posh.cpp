/*
TODO:
Run external apps
Make a remotely better command parser
Clean the code
*/
#include <iostream>
#include <filesystem>
#include <vector>
#include <string>

using namespace std;

string path = "/home/";
const string version = "pre-alpha";

#include "commands/commands.hpp"
#include "com/com.hpp"

using namespace com;
using namespace commands;

void getVer(int argc, vector<string> argv) {
	cout << "POSH version " << version << "\nhttps://github.com/Boops-Boops/POSH" << endl;;
}

void notExist(int argc, vector<string> argv) {
	if (argv[0] != "") {
		cout << "Command " + argv[0] + " does not exist." << endl;
	}
}

Commands registerCommands() {
	Commands pcom;

	pcom.addCommand(Command(getVer, "version"));
	pcom.addCommand(Command(ls, "ls"));
	pcom.addCommand(Command(cd, "cd"));
	pcom.addCommand(Command(cp, "cp"));
	pcom.addCommand(Command(mv, "mv"));
	pcom.addCommand(Command(rm, "rm"));
	pcom.addCommand(Command(ec, "echo"));
	pcom.addCommand(Command(run, "run"));
	pcom.addCommand(Command(notExist, "_default"));

	return pcom;
}

int main()
{	
	Commands pcom = registerCommands(); 
	cout << "Pine's OK Shell (POSH) version " << version << "\n";
	string cmd;
	while(1)
	{
		cout << string(path) << " > ";
		getline( cin, cmd );
		pcom.run(cmd);
	}
}