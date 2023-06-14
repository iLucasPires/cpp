#include "Bureaucrat.hpp"

void printHeader(std::string str) {
  std::cout << "======================================== \n"
            << str << "\n========================================\n";
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

int main(void) {
  printHeader("Constructors");
  Bureaucrat alex("Alex", 1);
  Bureaucrat bob("Bob", 149);
  Bureaucrat sheila("Sheila", 2);

  printHeader("Copy constructor");
  Bureaucrat copyAlex(alex);
  Bureaucrat copyBob(bob);
  Bureaucrat copySheila(sheila);

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

  printHeader("Destructors");
  return 0;
}
