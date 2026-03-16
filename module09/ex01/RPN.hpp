#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>
# include <stdexcept>
# include <stack>
# include <cstdlib>
# include <cctype>
# include <cstring>
# include <string>
# include <sstream>

class RPN 
{
    private:
        std::stack<int> _RpnStack;
    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();
		void pushNumber(int x);
		void executeOperator(char op);
		int reportStackTop();
};

#endif
