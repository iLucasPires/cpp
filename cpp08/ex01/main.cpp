#include "Span.hpp"

void testPDF()
{
    std::cout << "============= Test PDF ==============" << std::endl;
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void testOverflowLimint()
{

    std::cout << "============= Test Overflow Limint ==============" << std::endl;
    try
    {
        Span sp = Span(5);
        for (int i = 0; i < 6; i++)
        {
            sp.addNumber(rand() % 100);
        }

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }
}

void testEmptySpan()
{
    std::cout << "============= Test Empty Span ==============" << std::endl;
    try
    {
        Span sp(5);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void testSingleElementSpan()
{
    std::cout << "============= Test Single Element Span ==============" << std::endl;

    try
    {
        Span sp(5);
        sp.addNumber(10);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void testLargeSpan()
{
    std::cout << "============= Test Large Span ==============" << std::endl;
    try
    {
        Span sp(10000);
        for (int i = 1; i <= 10000; ++i)
        {
            sp.addNumber(i);
        }
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

int main()
{
    testPDF();
    testOverflowLimint();
    testEmptySpan();
    testSingleElementSpan();
    testLargeSpan();

    return 0;
}
