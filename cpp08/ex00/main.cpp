#include <vector>
#include <list>
#include "easyfind.hpp"

void testVector()
{
    std::vector<int> _vector;
    std::cout << "============= Test with vector =============" << std::endl;

    for (int i = 0; i < 10; i++)
    {
        _vector.push_back(i);
    }
    try
    {
        std::vector<int>::iterator it = easyfind(_vector, 3);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void testList()
{
    std::list<int> _list;
    std::cout << "============== Test with list ==============" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        _list.push_back(i + 109);
    }
    try
    {
        std::list<int>::iterator it = easyfind(_list, 3 + 109);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void testError()
{
    std::vector<int> _vector;
    std::cout << "============= Test with error ==============" << std::endl;

    for (int i = 0; i < 10; i++)
    {
        _vector.push_back(i);
    }
    try
    {
        std::vector<int>::iterator it = easyfind(_vector, 11);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void testEmpty()
{
    std::vector<int> _vector;
    std::cout << "============== Test with empty =============" << std::endl;

    try
    {
        std::vector<int>::iterator it = easyfind(_vector, 11);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void testOne()
{
    std::vector<int> _vector;
    std::cout << "=============== Test with one ==============" << std::endl;

    _vector.push_back(1);
    try
    {
        std::vector<int>::iterator it = easyfind(_vector, 1);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

int main()
{
    testVector();
    testList();
    testError();
    testEmpty();
    testOne();
    return (0);
}
