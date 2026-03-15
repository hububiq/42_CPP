#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>
# include <stdexcept>
# include <stack>
# include <cstdlib>
# include <cctype>

class RPN 
{
    private:
        std::stack<int> RpnStack;
    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();
};

#endif
