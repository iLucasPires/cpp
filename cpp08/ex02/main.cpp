#include "MutantStack.hpp"
#include <list>

void testIteradorList(void)
{
    std::list<int> mstack;
    mstack.push_back(5);
    mstack.push_back(17);
    mstack.push_back(3);
    mstack.push_back(5);
    mstack.push_back(737);
    mstack.push_back(0);
    std::list<int>::iterator it = mstack.begin();
    std::list<int>::iterator ite = mstack.end();
    std::cout << "============== Test Iterador List ==============" << std::endl;

    *it = 42;
    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
}

void testIterador(void)
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    std::cout << "============== Test Iterador ==============" << std::endl;

    *it = 42;
    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
}

void testConstIterador(void)
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::const_iterator it = mstack.begin();
    MutantStack<int>::const_iterator ite = mstack.end();
    std::cout << "============== Test Const Iterador ==============" << std::endl;

    // *it = 42; Error
    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
}

void testRevestIterador(void)
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::reverse_iterator it = mstack.rbegin();
    MutantStack<int>::reverse_iterator ite = mstack.rend();
    MutantStack<int>::reverse_iterator temp = mstack.rend();
    std::cout << "============== Test Reverse Iterador ==============" << std::endl;
    --temp;
    *temp = 42;
    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
}

void testConstRevestIterador(void)
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::const_reverse_iterator it = mstack.rbegin();
    MutantStack<int>::const_reverse_iterator ite = mstack.rend();

    std::cout << "============== Test Const Reverse Iterador ==============" << std::endl;
    // *it = 42; Error
    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
}

void testPDF(void)
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
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
}

int main(void)
{
    testIteradorList();
    testIterador();
    testConstIterador();
    testRevestIterador();
    testConstRevestIterador();
    // testPDF();
    return 0;
}
