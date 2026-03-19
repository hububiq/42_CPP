#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <string>
# include <stdexcept>
# include <vector>
# include <list>
# include <sstream>
# include <algorithm> //for begin() end() iterators

class PmergeMe
{
    private:
        std::vector<int> _vec;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();
        void pushNumber(int val);
        void validateInput(std::stringstream& ss);
};

#endif