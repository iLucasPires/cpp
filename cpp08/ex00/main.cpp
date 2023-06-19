#include <vector>
#include "easyfind.hpp"

int main()
{
    std::vector<int> oi;

    for (int i = 0; i < 10; i++)
    {
        oi.push_back(i);
    }

    std::cout << easyfind(oi, 2) << std::endl;

    return (0);
}
