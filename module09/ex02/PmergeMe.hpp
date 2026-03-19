#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <string>
# include <vector>
# include <list>
# include <sstream>

class PmergeMe
{
    private:
        std::vector<int> _vec;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();
        //func to filter signed integers
};

#endif