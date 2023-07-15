#include "BitcoinExchange.hpp"

int main(int argc, char const *argv[])
{
    if (argc != 2)
        return (1);
    // input do novo
    BitcoinExchange exchange(argv[1]);
    return 0;
}
