#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other)
{
    this->_RpnStack = other._RpnStack;
}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
        this->_RpnStack = other._RpnStack;
    return *this;
}

void RPN::pushNumber(int x)
{
	this->_RpnStack.push(x);
}

int RPN::executeOperator(char op)
{
	if (this->_RpnStack.size() < 2)
	{
		std::cout << "Error: wrong number of elements" << std::endl;
		return 1;
	}
	int b = this->_RpnStack.top();
	this->_RpnStack.pop();
	int a = this->_RpnStack.top();
	this->_RpnStack.pop();
	if (op == '+')
		this->_RpnStack.push(a + b);
	else if (op == '-')
		this->_RpnStack.push(a - b);
	else if (op == '*')
		this->_RpnStack.push(a * b);
	else if (op == '/')
	{
		if (b == 0)
			throw std::runtime_error("Error: Division by zero");
		this->_RpnStack.push(a / b);
	}
	return 0;
}

int RPN::reportStackTop()
{
    return this->_RpnStack.top();
}

int RPN::getStackSize()
{
	return this->_RpnStack.size();
}

RPN::~RPN() {}