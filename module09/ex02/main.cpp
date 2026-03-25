#include "PmergeMe.hpp"

//looping with for is quick on i.e. 3000 numbers. new/malloc or creating subvectors will take processor time for memory management
//vector is continuous segments, deque is separated continuous segments but even fast, probably faster for bigger inputs

int main(int argc, char **argv)
{
    PmergeMe< std::vector<int> > objV;
    PmergeMe< std::deque<int> > objD;
    std::stringstream ss;
    clock_t beforeV;
    clock_t afterV;
    clock_t beforeD;
    clock_t afterD;

    if (argc == 2)
        return std::cout << "Nothing to sort." << std::endl, 0;
    for (int i = 1; i < argc; i++)
        ss << argv[i] << " ";
    try 
    {
        objV.validateInput(ss);
        std::vector<int> temp = objV.getVector();  //will copy because string stream is empty now.
        for (size_t i = 0; i < temp.size(); i++)
            objD.pushNumber(temp[i]);
        beforeV = clock();
        objV.executeAlgo< std::vector< std::vector<int> > >();
        afterV = clock();
        objD.validateInput(ss);
        beforeD = clock();
        objD.executeAlgo< std::deque< std::deque<int> > >();
        afterD = clock();

    }
    catch (std::invalid_argument& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
	catch (std::out_of_range& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	catch (std::runtime_error& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
    std::cout << "Before:  ";
    for (int i = 1; i < argc; i++)
        std::cout << argv[i] << " ";
    std::cout << std::endl;
    std::vector<int> vecShow = objV.getVector();
    std::cout << "After:   ";
    for (int i = 0; i < argc - 1; i++)
        std::cout << vecShow[i] << " ";
    std::cout << std::endl;
    std::cout << "Time to process a range of " << argc - 1 << " arguments with std::" << "vector is : " <<              //should it be more generic?
    /*std::fixed << std::setprecision(1) <<*/ (float)(afterV - beforeV) / CLOCKS_PER_SEC * 1000000 << " us" << std::endl;
    std::cout << "Time to process a range of " << argc - 1 << " arguments with std::" << "deque is : " <<           
    /*std::fixed << std::setprecision(1) <<*/ (float)(afterD - beforeD) / CLOCKS_PER_SEC * 1000000 << " us" << std::endl;
    return 0;
}