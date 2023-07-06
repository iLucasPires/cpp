#include <iostream>
#include <Array.hpp>
#include <string>

#define RED "\x1b[38;5;196m"
#define YELLOW "\x1b[38;5;220m"
#define BLUE "\x1b[38;5;27m"

void testDefaultConstructor()
{
    std::cout << "============================= Test with default  ============================\n";
    Array<int> intArray;
    Array<std::string> stringArray;

    std::cout << "intArray.size() = " << intArray.size() << std::endl;
    std::cout << "stringArray.size() = " << stringArray.size() << std::endl;
}

void testIntArray()
{
    Array<int> intArray(5);

    std::cout << "============================ Test with int array ============================\n";

    std::cout << '[';
    for (unsigned int i = 0; i < intArray.size(); i++)
    {
        intArray[i] = i;
    }

    for (unsigned int i = 0; i < intArray.size(); i++)
    {
        std::cout << intArray[i] << " ";
    }

    std::cout << "]\n";
    std::cout << "intArray.size() = " << intArray.size() << std::endl;
}

void testStringArray()
{
    Array<std::string> stringArray(5);

    std::cout << "============================ Testing string array ===========================\n";

    std::cout << '[';
    for (unsigned int i = 0; i < stringArray.size(); i++)
    {
        stringArray[i] = "string";
    }

    for (unsigned int i = 0; i < stringArray.size(); i++)
    {
        std::cout << stringArray[i] << " ";
    }
    std::cout << "]\n";

    std::cout << "stringArray.size() = " << stringArray.size() << std::endl;
}

void testInvalidIndexOutOfRange()
{
    std::cout << "=================== Test with invalid index out of range ====================\n";

    Array<int> intArray(5);
    try
    {
        intArray[10] = 42;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

void testInvalidIndexNegative()
{
    std::cout << "====================== Test with invalid index negative =====================\n";
    Array<int> intArray(5);

    try
    {
        intArray[-1] = 42;
    }
    catch (std::exception &e)
    {

        std::cout << e.what() << std::endl;
    }
}

int main(int, char **)
{
    testDefaultConstructor();
    testIntArray();
    testStringArray();
    testInvalidIndexOutOfRange();
    testInvalidIndexNegative();
    return 0;
}
