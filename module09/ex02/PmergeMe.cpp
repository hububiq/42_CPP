#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other)
{
    this->_vec = other._vec;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        this->_vec = other._vec;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::pushNumber(int val)
{
    this->_vec.push_back(val);
}
void PmergeMe::validateInput(std::stringstream& ss)
{
    std::string token;

    while(ss >> token)
    {
        for (int i = 0; i < token.size(); i++)
        {
            if (!std::isdigit(token[i]))                                    //handle also minus
                throw std::invalid_argument("Wrong input.");
                // return std::cerr << "Wrong input" << std::endl, 1;
        }
        if (std::find(this->_vec.begin(), this->_vec.end(), std::stoi(token)) != this->_vec.end())
                throw std::invalid_argument("Duplicates");
        else
            this->pushNumber(std::stoi(token));
        std::cout << "Rozmiar to: " << this->_vec.size() << std::endl;
    }
}