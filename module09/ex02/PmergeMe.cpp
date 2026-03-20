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
        }
        if (std::find(this->_vec.begin(), this->_vec.end(), std::stoi(token)) != this->_vec.end())
                throw std::invalid_argument("Duplicates.");
        else
            this->pushNumber(std::stoi(token));
    }
    // std::cout << "Rozmiar to: " << this->_vec.size() << std::endl;
}

void PmergeMe::_algo(std::vector<int>& vec, int blockSize, int recStep)
{
    int elements = vec.size() / blockSize;
    if (elements < 2)
        return ;
    for (int i = 1; i < elements; i += 2)      
    {
        int rightWinner = (i + 1) * blockSize - 1;
        int leftWinner = i * blockSize - 1;
        if (vec[rightWinner] < vec[leftWinner])
        {
            for (int i = 0; i < blockSize; i++)
                std::swap(vec[rightWinner - i], vec[leftWinner - i]);
        }
    }
    for (int i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
    _algo(vec, blockSize * 2, recStep + 1);
}

void PmergeMe::executeAlgo()
{
    this->_algo(this->_vec, 1, 1);
}