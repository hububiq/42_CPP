#include "Span.hpp"
#include <numeric> //for adjacent_difference

Span::Span() {}

Span::Span(unsigned int N): _N(N)
{
    this->_intValues.reserve(_N);
}

Span::Span(const Span& other)
{
    this->_intValues = other._intValues;
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        this->_intValues = other._intValues;
    }
    return *this;
}

std::vector<int>& Span::getVector()
{
    return this->_intValues;
}

void Span::addNumber(int val)
{
    std::cout << "Current Size: " << _intValues.size() << " | Max Limit: " << _N << std::endl;
    if (this->_intValues.size() < this->_N)
        this->_intValues.push_back(val);
    else
        throw std::out_of_range("Can't add more members to vector");
}

void Span::addMultiple(const std::vector<int>& toInsert)
{
    unsigned int dist = std::distance(toInsert.begin(), toInsert.end());
    if (this->_intValues.size() + dist > this->_N)                                              //hedging size overflow
        throw std::out_of_range("Can't add more members to vector");
    this->_intValues.insert(this->_intValues.end(), toInsert.begin(), toInsert.end());
}

std::ptrdiff_t Span::shortestSpan()
{
    if (this->_intValues.size() > 1)
    {
        /* Pure STL method*/
        std::vector<int> copy = this->_intValues;                                               //vector handling memory itself
        std::cout << "\nSorted container for shortestSpan ";
        std::sort(copy.begin(), copy.end());
        for (int i = 0; i < this->_N; i++)
            std::cout << copy[i] << " ";
        std::vector<int> res(copy.size());                                                      //initialisation of new container for result
        std::adjacent_difference(copy.begin(), copy.end(), res.begin());
        std::cout << "\nContainer with adjacent differences ";
        std::vector<int>::iterator minRest = std::min_element(res.begin() + 1, res.end());      //ignoring first element from old container
        for (int i = 0; i < this->_N; i++)
            std::cout << res[i] << " ";
        std::cout << "Shortest span: ";
        return *minRest;                                                                        //the same as return res[std::distance(res.begin(), minRest)];

        /* ------ Sort and loop method below------*/
        // int i = 1;
        // int lowest = copy[i] - copy[i - 1];
        // while (i < this->_N)
        // {
        //     if ((copy[i] - copy[i - 1]) < lowest)
        //         lowest = copy[i] - copy[i - 1];
        //     i++;
        // }
        // return lowest;
    }
    else
        throw std::exception();
}

std::ptrdiff_t Span::longestSpan()
{
    if (this->_intValues.size() > 1)
    {
         std::vector<int>::iterator itMin = min_element(this->_intValues.begin(), this->_intValues.end());
         size_t indexMin = std::distance(_intValues.begin(), itMin);
         std::cout << "Min element is under index: " << indexMin << std::endl;
         std::vector<int>::iterator itMax = max_element(this->_intValues.begin(), this->_intValues.end());
         size_t indexMax = std::distance(_intValues.begin(), itMax);
         std::cout << "Max element is under index: " << indexMax << std::endl;
         std::cout << "Longest span: ";
         return _intValues[indexMax] - _intValues[indexMin];                                //the same as *indexMax - *indexMin
    }
    else
        throw std::exception();
}

Span::~Span() {}

