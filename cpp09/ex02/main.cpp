#include "PmergeMe.hpp"

void test_with_5()
{
    int const argc = 6;
    char const *argv[argc] = {"./PmergeMe", "5", "3",  "1" , "2" , "4"};
    PmergeMe pmergeMe(argc - 1, argv + 1);
}

void test_with_10()
{
    int const argc = 11;
    char const *argv[argc] = {"./PmergeMe", "5", "3",  "1" , "2" , "4", "9", "8", "7", "6", "10"};
    PmergeMe pmergeMe(argc - 1, argv + 1);
}

void test_with_100()
{
    int const argc = 101;
    char const *argv[argc] = {"./PmergeMe", "5", "3",  "1" , "2" , "4", "9", "8", "7", "6", "10",
                              "15", "13",  "11" , "12" , "14", "19", "18", "17", "16", "20",
                              "25", "23",  "21" , "22" , "24", "29", "28", "27", "26", "30",
                              "35", "33",  "31" , "32" , "34", "39", "38", "37", "36", "40",
                              "45", "43",  "41" , "42" , "44", "49", "48", "47", "46", "50",
                              "55", "53",  "51" , "52" , "54", "59", "58", "57", "56", "60",
                              "65", "63",  "61" , "62" , "64", "69", "68", "67", "66", "70",
                              "75", "73",  "71" , "72" , "74", "79", "78", "77", "76", "80",
                              "85", "83",  "81" , "82" , "84", "89", "88", "87", "86", "90",
                              "95", "93",  "91" , "92" , "94", "99", "98", "97", "96", "100"};
    PmergeMe pmergeMe(argc - 1, argv + 1);
}

int main(int const argc, char const *argv[])
{
    if (argc < 3)
    {
        std::cout << "./PmergeMe [integers]\nEnter at least 2 whole numbers" << std::endl;
        return 1;
    }
    PmergeMe pmergeMe(argc - 1, argv + 1);
    return 0;
}
