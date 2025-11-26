#include <fstream>
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cout << "Wrong input" << std::endl;
        return (1);
    }
    std::ifstream filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::ifstream srcFile("filename");
    std::ofstream dstFile("filename.replace");
    std::string = buffer;
    while (std::getline(srcFile, buffer))
    {
        dstFile << buffer << std::endl;
    }
    return (0);
}
