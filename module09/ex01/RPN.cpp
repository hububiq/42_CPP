#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other)
{
    this->RpnStack = other.RpnStack;
}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
        this->RpnStack = other.RpnStack;
    return *this;
}

RPN::~RPN() {}