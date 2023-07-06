#include <sstream>
#include "iter.hpp"

template <typename T>
void printValue(const T &value)
{
    std::cout << value << " ";
}

template <typename T>
void increment(T &value)
{
    value++;
}

template <typename T>
void checkEven(const T &value)
{
    std::cout << value ;
    if (value % 2 == 0)
        std::cout << " is even.";
    else
        std::cout << " is odd.";
    std::cout << '\n';
}

void testStringArray()
{

    std::cout << "============================ Testing string array ============================\n";
    std::string stringArray[] = {"hello", "world", "!"};

    std::cout << "Iterating over an array of strings: ";
    iter(stringArray, sizeof(stringArray) / sizeof(std::string), printValue<std::string>);
}

void testDoubleArray()
{
    std::cout << "\n============================ Testing double array ============================\n";
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    size_t doubleArrayLength = sizeof(doubleArray) / sizeof(double);

    std::cout << "Iterating over an array of doubles: ";
    iter(doubleArray, doubleArrayLength, printValue<double>);
}

void testIntArray()
{
    std::cout << "\n============================== Testing int array ==============================\n";

    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArrayLength = sizeof(intArray) / sizeof(int);

    std::cout << "Checking even numbers: \n";
    iter(intArray, intArrayLength, checkEven<int>);

    std::cout << "Printing int array: ";
    iter(intArray, intArrayLength, printValue<int>);
}

void testFloatArray()
{
    std::cout << "\n============================= Testing float array =============================\n";
    float floatArray[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    size_t floatArrayLength = sizeof(floatArray) / sizeof(float);

    std::cout << "Before increment: ";
    iter(floatArray, floatArrayLength, printValue<float>);

    iter(floatArray, floatArrayLength, increment<float>);

    std::cout << "\nAfter increment: ";
    iter(floatArray, floatArrayLength, printValue<float>);
}

int main()
{
    testStringArray();
    testDoubleArray();
    testIntArray();
    testFloatArray();
    std::cout << std::endl;

    return 0;
}
