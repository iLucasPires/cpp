#include "Intern.hpp"

Intern::Intern() {
  this->_forms[0].name = "shrubbery creation";
  this->_forms[0].build = &Intern::buildShrubberyCreationForm;

  this->_forms[1].name = "robotomy request";
  this->_forms[1].build = &Intern::buildRobotomyRequestForm;

  this->_forms[2].name = "presidential pardon";
  this->_forms[2].build = &Intern::buildPresidentialPardonForm;

  std::cout << "Intern constructor called\n";
}

Intern::Intern(const Intern &src) {
  std::cout << "Copy constructors called\n";
  *this = src;
}

Intern::~Intern() {}

Intern &Intern::operator=(Intern const &rhs) {
  if (this != &rhs) {
    for (int i = 0; i < FORMS_COUNT; i++) {
      this->_forms[i].name = rhs._forms[i].name;
      this->_forms[i].build = rhs._forms[i].build;
    }
  }
  return *this;
}

AForm *Intern::makeForm(std::string formName, std::string target) {
  for (int i = 0; i < FORMS_COUNT; i++) {
    if (formName == this->_forms[i].name) {
      std::cout << "Intern creates " << formName << '\n';
      return (this->*_forms[i].build)(target);
    }
  }
  std::cout << "Intern can't create " << formName << '\n';
  return NULL;
}

AForm *Intern::buildShrubberyCreationForm(std::string const target) {
  return new ShrubberyCreationForm(target);
}

AForm *Intern::buildRobotomyRequestForm(std::string const target) {
  return new RobotomyRequestForm(target);
}

AForm *Intern::buildPresidentialPardonForm(std::string const target) {
  return new PresidentialPardonForm(target);
}
