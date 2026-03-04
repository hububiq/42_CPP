#include "Span.hpp"

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

std::ptrdiff_t Span::shortestSpan()
{
    if (this->_intValues.size() > 1)
    {
        std::vector<int> copy = this->_intValues; //vector handling memory itself
        std::sort(copy.begin(), copy.end());
        int i = 1;
        int lowest = copy[i] - copy[i - 1];
        while (i < this->_N)
        {
            if ((copy[i] - copy[i - 1]) < lowest)
                lowest = copy[i] - copy[i - 1];
            i++;
        }
        std::cout << "Shortest span: ";
        return lowest;
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
         return _intValues[indexMax] - _intValues[indexMin];
    }
    else
        throw std::exception();
}

Span::~Span() {}

