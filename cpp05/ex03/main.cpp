#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


static void printHeader(std::string str)
{
    std::cout << "============================================================\n"
              << str
              << "\n============================================================\n";
}

int main(void)
{
    printHeader("Constructors");

    Bureaucrat *bureaucrat = new Bureaucrat("Bureaucrat", 134);

    AForm *form = new ShrubberyCreationForm("ShrubberyCreationForm");
    AForm *form2 = new RobotomyRequestForm("RobotomyRequestForm");
    AForm *form3 = new PresidentialPardonForm("PresidentialPardonForm");

    printHeader("Sign Form");
    bureaucrat->signForm(*form);
    bureaucrat->executeForm(*form);
    // bureaucrat->signForm(*form2);
    // bureaucrat->signForm(*form3);

    // printHeader("Execute Form");

    // bureaucrat->executeForm(*form);
    // bureaucrat->executeForm(*form2);
    // bureaucrat->executeForm(*form3);

    printHeader("Destructors");
    delete bureaucrat;
    delete form;
    delete form2;
    delete form3;

}
