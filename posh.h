inline void ls()
{
    for (const auto & entry : filesystem::directory_iterator(path))
        cout << string(entry.path()).erase(0, string(path).length()) << "\n";
}

inline void cd(string cmd)
{

    string arg = cmd.substr(3,cmd.find(' ', 4)-3);
    filesystem::path new_path = path / arg;
    if (filesystem::is_directory(new_path)) path = new_path;
    else cout << "Error: \"" << arg << "\" is not a directory" << "\n";
}

inline void cp(string cmd)
{
    filesystem::path to, from;
    from = path / cmd.substr(0, cmd.find(' ', 4)-3 );
    to = path / cmd.substr(cmd.find(' ', 4)+1);
    if(string(to) == string(from))
    {
        cout << "Can't copy file to itself" << "\n";
        return;
    }
    if(filesystem::exists(path / from))
    {
        filesystem::copy(path / from, path / to, filesystem::copy_options::recursive);
    }
    else cout << "Error: \"" << from << "\" doesn't exist." << "\n";
}

inline void mv(string cmd)
{
    filesystem::path to, from;
    from = path / cmd.substr(3, cmd.find(' ', 4)-3 );
    to = path / cmd.substr(cmd.find(' ', 4)+1);
    if(string(to) == string(from))
    {
        cout << "Can't move file to itself" << "\n";
        return;
    }
    if(filesystem::exists(path / from))
    {
        filesystem::copy(path / from, path / to, filesystem::copy_options::recursive);
        filesystem::remove_all(path / from);
    }
    else cout << "Error: \"" << from << "\" doesn't exist." << "\n";
}

inline void rm(string cmd)
{
    filesystem::path arg;
    arg = path / cmd.substr(3, cmd.find(' ', 4)-3 );
    if(filesystem::exists(path / arg))
        filesystem::remove(path / arg);
    else cout << "Error: \"" << arg << "\" doesn't exist." << "\n";
}

inline void ec(string cmd)
{
    string arg = cmd.substr(3);
    cout << arg << "\n";
}

inline void run(string cmd, bool pos = false)
{
    filesystem::path arg;
    arg = cmd.substr(pos*2, cmd.find(' ', 4)-3 );
    if(pos*2) arg = path / arg;
    if(filesystem::exists(arg)) cout << "POSH is unable to run external programs at the moment.\nIf you know how and want to help, start a pull request at https://github.com/Boops-Boops/POSH\n";
    else cout << "Error: \"" << arg << "\" doesn't exist." << "\n";
}