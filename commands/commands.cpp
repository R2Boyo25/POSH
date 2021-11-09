#include "commands.hpp"

using namespace std;
//using std::filesystem;

extern std::filesystem::path path;

namespace commands {
    void ls(int argc, vector<string> argv) 
    {
        for (const auto & entry : filesystem::directory_iterator(path)) {
            cout << string(entry.path()).erase(0, string(path).length()) << "\n";
        }
    }

    void cd(int argc, vector<string> argv)
    {
        if (argc == 2) {
            string newdir = argv[1];
            filesystem::path new_path = path / newdir;
            if (filesystem::is_directory(new_path)) {
                path = new_path;
            } else {
                cout << "Error: \"" << newdir << "\" is not a directory" << "\n";
            }
        } else if (argc > 2) {
            cout << "Too many arguments!" << endl;
        } else {
            cout << "Provide a directory!" << endl;
        }
    }

    void cp(int argc, vector<string> argv)
    {
        filesystem::path to, from;
        from = path / argv[1];
        to = path / argv[2];

        if (string(to) == string(from))
        {
            cout << "Can't copy file to itself" << "\n";
            return;
        }

        if (filesystem::exists(path / from))
        {
            filesystem::copy(path / from, path / to, filesystem::copy_options::recursive);
        } else {
            cout << "Error: \"" << from << "\" doesn't exist." << "\n";
        }
    }

    void mv(int argc, vector<string> argv)
    {
        filesystem::path to, from;
        from = path / argv[1];
        to = path / argv[2];
        if (string(to) == string(from))
        {
            cout << "Can't move file to itself" << "\n";
            return;
        }
        if (filesystem::exists(path / from))
        {
            filesystem::copy(path / from, path / to, filesystem::copy_options::recursive);
            filesystem::remove_all(path / from);
        }
        else {
            cout << "Error: \"" << from << "\" doesn't exist." << "\n";
        }
    }

    void rm(int argc, vector<string> argv)
    {
        filesystem::path arg;
        arg = path / argv[1];
        if (filesystem::exists(path / arg)) 
        {
            filesystem::remove(path / arg);
        } else {
            cout << "Error: \"" << arg << "\" doesn't exist." << "\n";
        }
    }

    void ec(int argc, vector<string> argv)
    {
        string arg = argv[1];
        cout << arg << "\n";
    }

    void run(int argc, vector<string> argv)
    {
        filesystem::path arg, npath;
        arg = argv[1];
        npath = path / arg;
        if (filesystem::exists(npath))
        { 
            cout << "POSH is unable to run external programs at the moment.\nIf you know how and want to help, start a pull request at https://github.com/Boops-Boops/POSH\n";
        } else { 
            cout << "Error: \"" << arg << "\" doesn't exist." << "\n";
        }
    }
}