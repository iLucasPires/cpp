#include "RPN.hpp"

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        std::cerr << "usage: ./rpn \"1 2 + 3 4 + *\"" << std::endl;
        return 1;
    }
    RPN rpn;
    rpn.calc(argv[1]);

    return 0;
}

