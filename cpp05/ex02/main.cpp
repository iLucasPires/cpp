#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    Bureaucrat *bureaucrat = new Bureaucrat("Bureaucrat", 1);
    AForm *form = new ShrubberyCreationForm("ShrubberyCreationForm");
    AForm *form2 = new RobotomyRequestForm("RobotomyRequestForm");
    AForm *form3 = new PresidentialPardonForm("PresidentialPardonForm");

    bureaucrat->signForm(*form);
    bureaucrat->signForm(*form2);
    bureaucrat->signForm(*form3);

}
