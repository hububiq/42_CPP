#ifndef SPAN_HPP
# define SPAN_HPP
# include <string>
# include <iostream>
# include <vector>
# include <stdexcept>
# include <algorithm>

class Span
{
    private:
        std::vector<int> _intValues;
        unsigned int _N;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int val);
        std::vector<int>& getVector();   //return reference to alter original version
        std::ptrdiff_t shortestSpan();
        std::ptrdiff_t longestSpan();
};

#endif