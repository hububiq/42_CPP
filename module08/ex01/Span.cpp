#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int N): _intValues(N) {}

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
    (this->getVector().push_back(val));
}

Span::~Span() {}

