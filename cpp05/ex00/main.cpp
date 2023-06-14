#include "Bureaucrat.hpp"

void printHeader(std::string str) {
  std::cout << "======================================== \n"
            << str << "\n========================================\n";
}

void testIncrementGrade(Bureaucrat &bureaucrat) {
  std::cout << bureaucrat << " trys to increment:";
  try {
    bureaucrat.incrementGrade();
    std::cout << "\033[32m Success";
  } catch (std::exception &e) {
    std::cout << "\033[31m " << e.what();
  }
  std::cout << "\033[0m\n";
}

void testDecrementGrade(Bureaucrat &bureaucrat) {
  std::cout << bureaucrat << " trys to decrement:";
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

  printHeader("Bureaucrat error");
  try {
    Bureaucrat error("Error", 0);
  } catch (std::exception &e) {
    std::cout << e.what() << '\n';
  };

  try {
    Bureaucrat error("Error", 151);
  } catch (std::exception &e) {
    std::cout << e.what() << '\n';
  };

  printHeader("Copy constructor");
  Bureaucrat copyAlex(alex);
  Bureaucrat copyBob(bob);
  Bureaucrat copySheila(sheila);

  printHeader("Bureaucrat incrementGrade");
  testIncrementGrade(alex);
  testIncrementGrade(bob);
  testIncrementGrade(sheila);
  testIncrementGrade(sheila);

  printHeader("Copy bureaucrat decrementGrade");
  testDecrementGrade(copyAlex);
  testDecrementGrade(copyBob);
  testDecrementGrade(copyBob);
  testDecrementGrade(copySheila);

  printHeader("Destructors");
  return 0;
}
