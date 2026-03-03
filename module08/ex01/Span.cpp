#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int N): _N(N)
{
    this->_intValues.reserve(N);
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
    if (this->_intValues.end() == this->_N)
        throw std::exception();
    this->getVector().push_back(val);
}

Span::~Span() {}

