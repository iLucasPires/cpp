#include "BitcoinExchange.hpp"

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        std::cout << "Error: invalid number of arguments" << std::endl;
        return 1;
    }
    // input do novo
    BitcoinExchange exchange(argv[1]);
    return 0;
}
