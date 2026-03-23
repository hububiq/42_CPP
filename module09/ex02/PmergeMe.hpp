#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <iostream>
# include <string>
# include <stdexcept>
# include <vector>
# include <sstream>
# include <algorithm> //for begin(), end() iterator, std::min()
# include <ctime>
# include <iomanip>

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

        std::vector<int> getVector();
        void pushNumber(int val);
        void validateInput(std::stringstream& ss);
        void executeAlgo();
        void jacobNumbersInsertion(dbVec& mainChain, dbVec& pendChain);
        void strugglerInsert(dbVec& mainChain, std::vector<int>& struggler);
        void rewriteVec(std::vector<int>& vec, dbVec& mainChain);
        void strugglerCut(std::vector<int>& struggler, bool& hasStruggler, std::vector<int>& vec, int blockSize);
        void elemWinnersCompare(int elements, int blockSize, std::vector<int>& vec);
        void initMainPend(std::vector<int>& vec, int blockSize, int elements, dbVec& mainChain, dbVec& pendChain);
        std::vector<int> generateJakobstahl(int elements);
        static bool compare(const std::vector<int>& a, const std::vector<int>& b);              //static for lower_bound compliance   
};

#endif