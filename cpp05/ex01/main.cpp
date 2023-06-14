#include "Bureaucrat.hpp"

void printHeader(std::string str) {
  std::cout << "======================================== \n"
            << str << "\n========================================\n";
}

void printDivider() {
  std::cout << "----------------------------------------\n";
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

void testSignForm(Bureaucrat &bureaucrat, Form &form) {
  bureaucrat.signForm(form);
}
int main(void) {
  printHeader("Constructors Bureaucrat");
  Bureaucrat alex("Alex", 1);
  Bureaucrat bob("Bob", 149);
  Bureaucrat sheila("Sheila", 2);

  printHeader("Copy constructor Bureaucrat");
  Bureaucrat copyAlex(alex);
  Bureaucrat copyBob(bob);
  Bureaucrat copySheila(sheila);

  printHeader("Constructors Form");
  Form form1("term of surrender", 1, 1);
  Form form2("tax form", 150, 150);
  Form form3("contract", 2, 2);

  printHeader("Sign Form");

  testSignForm(alex, form1);
  testSignForm(alex, form2);
  testSignForm(alex, form3);

  printDivider();
  testSignForm(bob, form1);
  testSignForm(bob, form2);
  testSignForm(bob, form3);

  printDivider();
  testSignForm(sheila, form1);
  testSignForm(sheila, form2);
  testSignForm(sheila, form3);

  printHeader("Form outside the grade");
  try {
    Form invalidForm("Invalid Form", 0, 0);
  } catch (std::exception &e) {
    std::cout << "Exception caught: \033[31m" << e.what() << "\033[0m"
              << std::endl;
  }
  printDivider();
  try {
    Form invalidForm("Invalid Form", 151, 151);
  } catch (std::exception &e) {
    std::cout << "Exception caught: \033[31m" << e.what() << "\033[0m\n";
  }

  printHeader("Destructors");
  return 0;
}
