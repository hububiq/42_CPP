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
    std::cout << "Only here creating the main and pend in step:" << recStep << std::endl;
    // std::cout << vec[blockSize - 1] << std::endl;
    std::vector<std::vector<int>> mainChain;
    std::vector<std::vector<int>> pendChain;
    for (int i = 1; i < elements; i++)
    {
        if (i % 2 != 0)
        {
            std::vector<int> tempPend;
            for (int j = 0; j < blockSize; j++)
            {
                tempPend.push_back(vec[i * j]);
            }
            pendChain.push_back(tempPend);
        }
        else if (i % 2 == 0)
        {
            std::vector<int> tempMain;
            for (int j = 0; j < blockSize; j++)
            {
                tempMain.push_back(vec[i * j]);
            }
            mainChain.push_back(tempMain);
        }
    }
    for (int i = 0; i < mainChain.size(); i++)
    {
        for (int j = 0; j < mainChain[i].size(); j++)
            std::cout << mainChain[i][j] << " ";
        std::cout << "TO byl main" << std::endl;
    }
    // finish making main and pend
    // create more generic logic and push to main with a helper or pushing straitaway the first loser to frontal main


    //generate jacobstahl
    //insert from pend to main based on indexes in pend compared to jacobsthal from lower to higher
    //remember about "strugglers"
    //split with helpers and objectify main algo scope
    //add time measurement

    // for (int i = 0; i < pendChain.size(); i++)
    // {
    //     for (int j = 0; j < pendChain[i].size(); j++)
    //         std::cout << pendChain[i][j] << " ";
    //     std::cout << "TO byl pend" << std::endl;
    // }
}

void PmergeMe::executeAlgo()
{
    this->_algo(this->_vec, 1, 1);
}