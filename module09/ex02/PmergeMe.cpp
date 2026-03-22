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
    std::vector<int> b1(vec.begin(), vec.begin() + blockSize);
    std::vector<int> a1(vec.begin() + blockSize, vec.begin() + 2 * blockSize);
    mainChain.push_back(b1);
    mainChain.push_back(a1);
    for (int i = 2; i < elements - 1; i += 2)
    {
        std::vector<int> bBlock(vec.begin() + i * blockSize, vec.begin() + (i + 1) * blockSize);
        pendChain.push_back(bBlock);
        std::vector<int> aBlock(vec.begin() + (i + 1) * blockSize, vec.begin() + (i + 2) * blockSize);
        mainChain.push_back(aBlock);
    }
}

std::vector<int> PmergeMe::generateJakobstahl(int elements)
{
    std::vector<int> jakobNumbers;
    jakobNumbers.push_back(0);
    jakobNumbers.push_back(1);
    int i = 2;
    while (true)
    {
        int jakobNumb = jakobNumbers[i - 1] + 2 * jakobNumbers[i - 2];
        jakobNumbers.push_back(jakobNumb);
        if (jakobNumb > elements + 1)
            break;
        i++;
    }
    return jakobNumbers;
}

bool PmergeMe::compare(const std::vector<int>& a, const std::vector<int>& b)
{
    return a.back() < b.back();
}

void PmergeMe::_algo(std::vector<int>& vec, int blockSize, int recStep)
{
    int elements = vec.size() / blockSize;
    if (elements < 2)
        return ;
    std::vector<int> struggler;
    bool hasStruggler = false;
    if (elements % 2 != 0) 
    {
        int start = vec.size() - blockSize;         //cutting out the struggler
        for (int k = 0; k < blockSize; k++) 
        {
            struggler.push_back(vec[start + k]);
        }
        vec.erase(vec.begin() + start, vec.end());
        hasStruggler = true;
    }
    for (int i = 1; i < elements; i += 2)      //comparing elements
    {
        int rightWinner = (i + 1) * blockSize - 1;
        int leftWinner = i * blockSize - 1;
        if (vec[rightWinner] < vec[leftWinner])
        {
            for (int j = 0; j < blockSize; j++)
                std::swap(vec[rightWinner - j], vec[leftWinner - j]);
        }
    }
    _algo(vec, blockSize * 2, recStep + 1);
    dbVec mainChain;
    dbVec pendChain;
    initMainPend(vec, blockSize, elements, mainChain, pendChain);
    if (!pendChain.empty())
    {
        std::vector<int> jN = generateJakobstahl(pendChain.size());
        int inserted = 1;
        int lastPushedIndex = -1;
        for (int i = 3; i < jN.size(); i++)
        {
            int currentJacob = jN[i];
            int startIndex = std::min((int)pendChain.size() - 1, currentJacob - 2);             //safety for not going out of pend if its too short comparing to Jakobstahl number
            for (int j = startIndex; j > lastPushedIndex; j--) //taking lower and lower b from pendChain
            {
                int pairNum = j + 2;                           //reverse logic to pair up to main
                int limit = pairNum + inserted - 1;
                int actualLimit = std::min((int)mainChain.size(), limit); //cast because min takes size_t
                std::vector<std::vector<int> >::iterator it = std::lower_bound(
                    mainChain.begin(), 
                    mainChain.begin() + actualLimit, 
                    pendChain[j], 
                    compare); //pointer to function
                    mainChain.insert(it, pendChain[j]);
                    inserted++;
            }
            lastPushedIndex = startIndex;
            if (lastPushedIndex >= (int)pendChain.size() - 1)
                break;
        }
    }
    if (hasStruggler) 
    {
        std::vector<std::vector<int> >::iterator it = std::lower_bound(
             mainChain.begin(), 
             mainChain.end(), 
             struggler, 
             compare
         );
         mainChain.insert(it, struggler);
    }
    vec.clear(); 
    for (size_t i = 0; i < mainChain.size(); ++i) 
    {
        for (size_t j = 0; j < mainChain[i].size(); ++j) 
            vec.push_back(mainChain[i][j]);
    }

    for (int i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::executeAlgo()
{
    this->_algo(this->_vec, 1, 1);
}