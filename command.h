inline void ls()
{
    for (const auto & entry : fs::directory_iterator(path)) cout << string(entry.path()).erase(0, string(path).length()) << "\n";
}

inline void cd(string cmd)
{
    if (cmd.length() < 4) return;
    string arg = cmd.substr(3);
    fs::path new_path = path / arg;
    if (fs::is_directory(new_path)) path = new_path;
    else cout << "Error: \"" << arg << "\" is not a directory" << "\n";
}

inline void cp(string cmd)
{
    fs::path to, from;
    from = path / cmd.substr(3, cmd.find(' ', 4)-3 );
    to = path / cmd.substr(cmd.find(' ', 4)+1);
    if(string(to) == string(from))
    {
        cout << "Can't copy file to itself" << "\n";
        return;
    }
    if(fs::exists(path / from))
    {
        fs::copy(path / from, path / to, fs::copy_options::recursive);
    }
    else cout << "Error: \"" << from << "\" doesn't exist." << "\n";
}

inline void mv(string cmd)
{
    fs::path to, from;
    from = path / cmd.substr(3, cmd.find(' ', 4)-3 );
    to = path / cmd.substr(cmd.find(' ', 4)+1);
    if(string(to) == string(from))
    {
        cout << "Can't move file to itself" << "\n";
        return;
    }
    if(fs::exists(path / from))
    {
        fs::copy(path / from, path / to, fs::copy_options::recursive);
        fs::remove_all(path / from);
    }
    else cout << "Error: \"" << from << "\" doesn't exist." << "\n";
}

inline void rm(string cmd)
{
    fs::path arg;
    arg = path / cmd.substr(3, cmd.find(' ', 4)-3 );
    if(fs::exists(path / arg))
        fs::remove(path / arg);
    else cout << "Error: \"" << arg << "\" doesn't exist." << "\n";
}

inline void ec(string cmd)
{
    if (cmd.length() < 4) return;
    string arg = cmd.substr(3);
    cout << arg << "\n";
}

inline void run(string cmd)
{
    fs::path arg;
    arg = path / cmd.substr(3, cmd.find(' ', 4)-3 );
    if(fs::exists(path / arg))
        fs::remove(path / arg);
    else cout << "Error: \"" << arg << "\" doesn't exist." << "\n";
}