#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <string>
# include <stdexcept>
# include <vector>
# include <deque>
# include <sstream>
# include <algorithm> //for begin(), end() iterator, std::min()
# include <ctime>
# include <iomanip>
# include <cstdlib>


template <typename T>
class PmergeMe
{
    private:
        T _container;
        typedef std::vector<T> dbVec;
        typedef std::deque<T> dbDeq;
        template <typename D>
        void _algo(T& container, int blockSize, int recStep);                          //private for work, public function just for starter
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        T getVector();
        void pushNumber(int val);
        void validateInput(std::stringstream& ss);
        template <typename D>
        void executeAlgo();
        template <typename D>
        void jacobNumbersInsertion(D& mainChain, D& pendChain);
        template <typename D>
        void strugglerInsert(D& mainChain, T& struggler);
        template <typename D>
        void rewriteVec(T& cont, D& mainChain);
        void strugglerCut(T& struggler, bool& hasStruggler, T& cont, int blockSize);
        void elemWinnersCompare(int elements, int blockSize, T& cont);
        template <typename D>
        void initMainPend(T& cont, int blockSize, int elements, D& mainChain, D& pendChain);
        T generateJakobstahl(int elements);
        static bool compare(const T& a, const T& b);              //static for lower_bound compliance   
};

template <typename T>
PmergeMe<T>::PmergeMe() {}

template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe& other)
{
    this->_container = other._container;
}

template <typename T>
PmergeMe<T>& PmergeMe<T>::operator=(const PmergeMe& other)
{
    if (this != &other)
    {
        this->_container = other._container;
    }
    return *this;
}

template <typename T>
PmergeMe<T>::~PmergeMe() {}

template <typename T>
T PmergeMe<T>::getVector()
{
    return this->_container;
}

template <typename T>
void PmergeMe<T>::pushNumber(int val)
{
    this->_container.push_back(val);
}

template <typename T>
void PmergeMe<T>::validateInput(std::stringstream& ss)
{
    std::string token;

    while(ss >> token)
    {
        for (unsigned int i = 0; i < token.size(); i++)
        {
            if (!std::isdigit(token[i]))                                    //handle also minus
                throw std::invalid_argument("Wrong input.");
        }
        if (std::find(this->_container.begin(), this->_container.end(), std::atoi(token.c_str())) != this->_container.end())
                throw std::invalid_argument("Duplicates.");
        else
            this->pushNumber(std::atoi(token.c_str()));
    }
}

template <typename T>
bool PmergeMe<T>::compare(const T& a, const T& b)
{
    return a.back() < b.back();
}
															//"template" twice because definition outside class body
template <typename T>                                       //unwrapping the class first
template <typename D>                                       //only now the function nested.
void PmergeMe<T>::jacobNumbersInsertion(D& mainChain, D& pendChain)
{
    T jN = generateJakobstahl(pendChain.size());
    int inserted = 1;
    int lastPushedIndex = -1;
    for (unsigned int i = 3; i < jN.size(); i++)
    {
        int currentJacob = jN[i];
        int startIndex = std::min((int)pendChain.size() - 1, currentJacob - 2);             //safety for not going out of pend if its too short comparing to Jakobstahl number
        for (int j = startIndex; j > lastPushedIndex; j--)                                  //taking lower and lower b from pendChain
        {
            int pairNum = j + 2;                                                            //reverse logic to pair up to main, which in order
            int limit = pairNum + inserted - 1;
            int actualLimit = std::min((int)mainChain.size(), limit);                       //cast because min takes both types the same
            typename D::iterator it = std::lower_bound(
                mainChain.begin(), 
                mainChain.begin() + actualLimit, 
                pendChain[j], 
                compare);                                                                   //pointer to function
            mainChain.insert(it, pendChain[j]);
            inserted++;
        }
        lastPushedIndex = startIndex;
        if (lastPushedIndex >= (int)pendChain.size() - 1)
            break;
    }
}

template <typename T>
template <typename D>
void PmergeMe<T>::strugglerInsert(D& mainChain, T& struggler)
{
    typename D::iterator it = std::lower_bound(
             mainChain.begin(), 
             mainChain.end(), 
             struggler, 
             compare);
    mainChain.insert(it, struggler);
}

template <typename T>
template <typename D>
void PmergeMe<T>::rewriteVec(T& cont, D& mainChain)
{
    cont.clear(); 
    for (size_t i = 0; i < mainChain.size(); i++) 
    {
        for (size_t j = 0; j < mainChain[i].size(); j++) 
            cont.push_back(mainChain[i][j]);
    }
}

template <typename T>
void PmergeMe<T>::strugglerCut(T& struggler, bool& hasStruggler, T& cont, int blockSize)
{
     int start = cont.size() - blockSize;             //cutting out the struggler
        for (int k = 0; k < blockSize; k++) 
            struggler.push_back(cont[start + k]);
        cont.erase(cont.begin() + start, cont.end());
        hasStruggler = true;
}

template <typename T>
void PmergeMe<T>::elemWinnersCompare(int elements, int blockSize, T& cont)
{
    for (int i = 1; i < elements; i += 2)               //comparing elements
    {
        int rightWinner = (i + 1) * blockSize - 1;
        int leftWinner = i * blockSize - 1;
        if (cont[rightWinner] < cont[leftWinner])
        {
            for (int j = 0; j < blockSize; j++)
                std::swap(cont[rightWinner - j], cont[leftWinner - j]);
        }
    }
}

template <typename T>
template <typename D>
void PmergeMe<T>::initMainPend(T& cont, int blockSize, int elements, D& mainChain, D& pendChain)
{
    T b1(cont.begin(), cont.begin() + blockSize);
    T a1(cont.begin() + blockSize, cont.begin() + 2 * blockSize);
    mainChain.push_back(b1);
    mainChain.push_back(a1);
    for (int i = 2; i < elements - 1; i += 2)
    {
        T bBlock(cont.begin() + i * blockSize, cont.begin() + (i + 1) * blockSize);
        pendChain.push_back(bBlock);
        T aBlock(cont.begin() + (i + 1) * blockSize, cont.begin() + (i + 2) * blockSize);
        mainChain.push_back(aBlock);
    }
}

template <typename T>
T PmergeMe<T>::generateJakobstahl(int elements)
{
    T jakobNumbers;
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

template <typename T>
template <typename D>
void PmergeMe<T>::_algo(T& container, int blockSize, int recStep)
{
    T struggler;
    bool hasStruggler = false;
    D mainChain;
    D pendChain;

    int elements = container.size() / blockSize;
    if (elements < 2)
        return ;
    if (elements % 2 != 0) 
        this->strugglerCut(struggler, hasStruggler, container, blockSize);
    this->elemWinnersCompare(elements, blockSize, container);
    this->template _algo<D>(container, blockSize * 2, recStep + 1);
    this->initMainPend(container, blockSize, elements, mainChain, pendChain);
    if (!pendChain.empty())
        this->jacobNumbersInsertion(mainChain, pendChain);
    if (hasStruggler) 
        this->strugglerInsert(mainChain, struggler);
    this->rewriteVec(container, mainChain);
}

template <typename T>
template <typename D>
void PmergeMe<T>::executeAlgo()                 
{
    this->template _algo<D>(this->_container, 1, 1);        //C++ requires "template" keyword because _algo is a dependent template
}

#endif