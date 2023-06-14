#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void printHeader(std::string str) {
  std::cout << "======================================== \n"
            << str << "\n========================================\n";
}

void printDivider() {
  std::cout << "----------------------------------------\n";
}

void printFooter() {
  std::cout << "________________________________________\n";
}

void testIncrementGrade(Bureaucrat &bureaucrat) {
  std::cout << bureaucrat << ":";
  try {
    bureaucrat.incrementGrade();
    std::cout << "\033[32m Success";
  } catch (std::exception &e) {
    std::cout << "\033[31m " << e.what();
  }
  std::cout << "\033[0m\n";
}

void testDecrementGrade(Bureaucrat &bureaucrat) {
  std::cout << bureaucrat << ":";
  try {
    bureaucrat.decrementGrade();
    std::cout << "\033[32m Success";
  } catch (std::exception &e) {
    std::cout << "\033[31m " << e.what();
  }
  std::cout << "\033[0m\n";
}

void testSignAForm(Bureaucrat &bureaucrat, AForm &Aform) {
  bureaucrat.signForm(Aform);
}

void testExecuteAForm(Bureaucrat &bureaucrat, AForm &Aform) {
  bureaucrat.executeForm(Aform);
}

int main(void) {
  printHeader("Constructors Bureaucrat");
  Bureaucrat alex("Alex", 1);
  Bureaucrat bob("Bob", 145);
  Bureaucrat sheila("Sheila", 2);

  printHeader("Copy constructor Bureaucrat");
  Bureaucrat copyAlex(alex);
  Bureaucrat copyBob(bob);
  Bureaucrat copySheila(sheila);

  printHeader("Constructors AForm");
  AForm *aForm1 = new ShrubberyCreationForm("termOfUse");
  AForm *aForm2 = new RobotomyRequestForm("contract");
  AForm *aForm3 = new PresidentialPardonForm("taxes");

  printHeader("Bureaucrat incrementGrade");
  testIncrementGrade(alex);
  testIncrementGrade(bob);
  testIncrementGrade(sheila);
  testIncrementGrade(sheila);

  printHeader("Bureaucrat decrementGrade");
  testDecrementGrade(copyAlex);
  testDecrementGrade(copyBob);
  testDecrementGrade(copyBob);
  testDecrementGrade(copySheila);

  printHeader("Sign AForm");

  testSignAForm(alex, *aForm1);
  testSignAForm(alex, *aForm2);
  testSignAForm(alex, *aForm3);

  printDivider();
  testSignAForm(bob, *aForm1);
  testSignAForm(bob, *aForm2);
  testSignAForm(bob, *aForm3);

  printDivider();
  testSignAForm(sheila, *aForm1);
  testSignAForm(sheila, *aForm2);
  testSignAForm(sheila, *aForm3);

  printHeader("Execute AForm");
  testExecuteAForm(alex, *aForm1);
  testExecuteAForm(alex, *aForm2);
  testExecuteAForm(alex, *aForm3);

  printDivider();
  testExecuteAForm(bob, *aForm1);
  testExecuteAForm(bob, *aForm2);
  testExecuteAForm(bob, *aForm3);

  printDivider();
  testExecuteAForm(sheila, *aForm1);
  testExecuteAForm(sheila, *aForm2);
  testExecuteAForm(sheila, *aForm3);

  printHeader("Bureaucrat inside the grade");
  try {
    Bureaucrat invalidGrade("Invalid", 1);
    invalidGrade.incrementGrade();
  } catch (std::exception &e) {
    std::cout << "Exception caught: \033[31m" << e.what() << "\033[0m\n";
  }

  printDivider();

  try {
    Bureaucrat invalidGrade("Invalid", 150);
    invalidGrade.decrementGrade();
  } catch (std::exception &e) {
    std::cout << "Exception caught: \033[31m" << e.what() << "\033[0m\n";
  }

  printHeader("Bureaucrat outside the grade");
  try {
    Bureaucrat invalidGrade("Invalid", 0);
  } catch (std::exception &e) {
    std::cout << "Exception caught: \033[31m" << e.what() << "\033[0m\n";
  }
  printDivider();
  try {
    Bureaucrat invalidGrade("Invalid", 151);
  } catch (std::exception &e) {
    std::cout << "Exception caught: \033[31m" << e.what() << "\033[0m\n";
  }

  printHeader("Destructors");
  return 0;
}
