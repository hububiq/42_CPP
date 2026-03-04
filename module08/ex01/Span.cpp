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

unsigned int Span::shortestSpan() const
{

}

unsigned int Span::longestSpan() const
{
    
}

Span::~Span() {}

