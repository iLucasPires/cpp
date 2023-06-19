#include <iostream>
#include <string>
#include <sstream>
#include "iter.hpp"

template<typename T>
void printValue(const T& value)
{
    std::cout << value << " ";
}

template<typename T>
void increment(T& value)
{
    value++;
}

template<typename T>
void checkEven(const T& value)
{
    if (value % 2 == 0)
        std::cout << value << " é par." << std::endl;
    else
        std::cout << value << " é ímpar." << std::endl;
}

template<typename T>
void printAsString(const T& value)
{
    std::stringstream ss;
    ss << value;
    std::cout << ss.str() << " ";
}

int main()
{
    std::string stringArray[] = { "Olá", "Mundo", "!" };
    size_t stringArrayLength = sizeof(stringArray) / sizeof(std::string);

    std::cout << "Iteração em um array de strings: ";
    ::iter(stringArray, stringArrayLength, printValue<std::string>);
    std::cout << std::endl;

    double doubleArray[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    size_t doubleArrayLength = sizeof(doubleArray) / sizeof(double);

    std::cout << "Iteração em um array de doubles: ";
    ::iter(doubleArray, doubleArrayLength, printAsString<double>);
    std::cout << std::endl;

    int intArray[] = { 1, 2, 3, 4, 5 };
    size_t intArrayLength = sizeof(intArray) / sizeof(int);

    std::cout << "Verificação de números pares: " << std::endl;
    ::iter(intArray, intArrayLength, checkEven<int>);

    float floatArray[] = { 1.1f, 2.2f, 3.3f, 4.4f, 5.5f };
    size_t floatArrayLength = sizeof(floatArray) / sizeof(float);

    std::cout << "Antes do incremento: ";
    ::iter(floatArray, floatArrayLength, printValue<float>);
    std::cout << std::endl;

    ::iter(floatArray, floatArrayLength, increment<float>);

    std::cout << "Após o incremento: ";
    ::iter(floatArray, floatArrayLength, printValue<float>);
    std::cout << std::endl;

    return 0;
}
