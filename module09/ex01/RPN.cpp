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

void RPN::executeOperator(char op)
{
	if (this->_RpnStack.size() < 2)
		throw std::runtime_error("Error: wrong number of elements");
	int b = this->_RpnStack.top(); 
	std::cout << "Top po pierwszym razie" << b << std::endl;
	this->_RpnStack.pop();
	int a = this->_RpnStack.top();
	std::cout << "Top po drugim razie" << a << std::endl;
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
	return ;
}

int RPN::reportStackTop()
{
    return this->_RpnStack.top();
}

RPN::~RPN() {}