#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

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
  std::cout << '\n';
}

void testExecuteAForm(Bureaucrat &bureaucrat, AForm &Aform) {
  bureaucrat.executeForm(Aform);
  std::cout << '\n';
}

AForm *testMakeForm(Intern &intern, std::string formName, std::string target) {
  AForm *aForm = intern.makeForm(formName, target);
  if (aForm != NULL) {
    std::cout << "\033[32mSuccess to create \n";
  } else if (aForm == NULL) {
    std::cout << "\033[31mFailed to create \n";
  }
  std::cout << "\033[0m\n";
  return aForm;
}

int main(void) {
  printHeader("Constructors Bureaucrat");
  Bureaucrat alex("Alex", 1);
  Bureaucrat bob("Bob", 145);
  Bureaucrat sheila("Sheila", 2);

  printHeader("Constructors Intern");
  Intern intern;

  printHeader("Constructors AForm");
  AForm *aForm1 = testMakeForm(intern, "shrubbery creation", "Bender");
  AForm *aForm2 = testMakeForm(intern, "robotomy request", "Bender");
  AForm *aForm3 = testMakeForm(intern, "presidential pardon", "Bender");
  testMakeForm(intern, "unknown", "Bender");

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

  printHeader("Destructors");
  delete aForm1;
  delete aForm2;
  delete aForm3;
  return 0;
}
