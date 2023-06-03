#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat b("b", 1);
        std::cout << b << '\n';
        b.incrementGrade();
        std::cout << b << '\n';
        b.decrementGrade();
        std::cout << b << '\n';
        b.decrementGrade();
        std::cout << b << '\n';
    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << e.what() << '\n';
    }
}
