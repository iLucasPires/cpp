#include "PmergeMe.hpp"

int main(int const argc, char const *argv[])
{
    if (argc < 2)
    {
        std::cout << "./PmergeMe [integers]" << std::endl;
        return 1;
    }
    PmergeMe pmergeMe(argc - 1, argv + 1);
    return 0;
}
