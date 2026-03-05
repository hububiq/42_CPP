#include "MutantStack.hpp"
#include "MutantStack.tpp"

int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    mstack.pop();
    // std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    // std::cout << mstack.size() << std::endl;
    std::cout << mstack.top() << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    MutantStack<int>::iterator it2 = mstack.begin() + 2;
    std::cout << *it2 << std::endl;
    // std::stack<int> s;
    // MutantStack<int>::iterator it2 = s.begin();
    // std::cout << *it2 << std::endl;
    return 0;
}