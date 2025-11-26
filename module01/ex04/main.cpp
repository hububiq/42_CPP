#include <fstream>
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Wrong input" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream srcFile(filename);                //constructors of that class
    std::ofstream dstFile(filename + ".replace");
    std::string buffer;
    if (!srcFile.is_open())
    {
        std::cerr << "Error with opening" << std::endl;
        return 1;
    }
    if (!dstFile.is_open())
    {
        std::cerr << "Can't create destination file" << std::endl;
        return 1;
    }
    while (std::getline(srcFile, buffer))
    {
        size_t pos = 0;
        while (1)
        {
            pos = buffer.find(s1, pos);
            if (pos == std::string::npos)   //didnt find s1. must check it now, otherwise it goes hell out of space when trying to use any functions with pos on buffer.
                break ;
            buffer.erase(pos, s1.length());
            buffer.insert(pos, s2);
            pos = pos + s2.length();        //pos can go to the end, then it breaks above on the guard
        }
        dstFile << buffer << std::endl;
    }
    return 0;
}
