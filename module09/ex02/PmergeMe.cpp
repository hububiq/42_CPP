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
}

void PmergeMe::initMainPend(std::vector<int>& vec, int blockSize, int elements, dbVec& mainChain, dbVec& pendChain)
{
    for (int i = 0; i < 2; i++)
    {
        int start = i * blockSize;
        std::vector<int> AB(vec.begin() + start, vec.begin() + start + blockSize);
        mainChain.push_back(AB);
    }
    for (int i = 2; i < elements - 1; i += 2)
    {
        std::vector<int> bBlock(vec.begin() + i * blockSize, vec.begin() + (i + 1) * blockSize);
        pendChain.push_back(bBlock);
        std::vector<int> aBlock(vec.begin() + (i + 1) * blockSize, vec.begin() + (i + 2) * blockSize);
        mainChain.push_back(aBlock);
    }
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
    std::cout << "Only here creating the main and pend in step:" << recStep << std::endl;
    dbVec mainChain;
    dbVec pendChain;
    initMainPend(vec, blockSize, elements, mainChain, pendChain);
    
    //struggler also here?

    for (int i = 0; i < mainChain.size(); i++)
    {
        for (int j = 0; j < mainChain[i].size(); j++)
            std::cout << mainChain[i][j] << " ";
        std::cout << "TO byl main" << std::endl;
    }
    
    for (int i = 0; i < pendChain.size(); i++)
    {
        for (int j = 0; j < pendChain[i].size(); j++)
        std::cout << pendChain[i][j] << " ";
    std::cout << "TO byl pend" << std::endl;
    }
//generate jacobstahl
//insert from pend to main based on indexes in pend compared to jacobsthal from lower to higher
//clear or overwrite original vector and use it in next insertion
//remember about "strugglers"
//split with helpers and objectify main algo scope
//add time measurement
}

void PmergeMe::executeAlgo()
{
    this->_algo(this->_vec, 1, 1);
}