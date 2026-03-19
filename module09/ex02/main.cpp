#include "PmergeMe.hpp"

//perhaps create validating function first
//while pushing to vector, start assigning those pairs to struct? enum?
//resolve duplicates, in raw argv[1]. vector has no find like string but should take from global with range iterators

int main(int argc, char **argv)
{
    std::stringstream ss(argv[1]);
    std::vector<int> a;
    std::string token;

    while(ss >> token)
    {
        for (int i = 0; i < token.size(); i++)
        {
            if (!std::isdigit(token[i]))                     //handle also minus
                return std::cerr << "Wrong input" << std::endl, 1;
            // if (argv[1].find(token))
            //     return std::cerr << "There is duplicate in input" << std::endl, 1;
            if (token.size() == 1)
                a.push_back((token[i]) - '0');
            else
                a.push_back(std::stoi(token));
            if (token.find(argv[1]))
                std::cout << "Duplicates" << std::endl;
        }
        // std::cout << a.size() << std::endl;
    }

    return 0;
}