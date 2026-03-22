#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <string>
# include <stdexcept>
# include <vector>
# include <list>
# include <sstream>
# include <algorithm> //for begin(), end() iterator, std::min()

class PmergeMe
{
    private:
        std::vector<int> _vec;
        void _algo(std::vector<int>& vec, int blockSize, int recStep);                          //private for work, public function just for starter
    public:
        typedef std::vector<std::vector<int>> dbVec;
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        void pushNumber(int val);
        void validateInput(std::stringstream& ss);
        void executeAlgo();
        void initMainPend(std::vector<int>& vec, int blockSize, int elements, dbVec& mainChain, dbVec& pendChain);
        std::vector<int> generateJakobstahl(int elements);
        static bool compare(const std::vector<int>& a, const std::vector<int>& b);              //static for lower_bound compliance
    
};

#endif