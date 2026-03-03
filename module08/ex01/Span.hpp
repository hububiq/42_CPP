#ifndef SPAN_HPP
# define SPAN_HPP
# include <string>
# include <iostream>
# include <vector>

class Span
{
    private:
        std::vector<int> _intValues;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int val);
        std::vector<int>& getVector();   //return reference to alter original version
};

#endif