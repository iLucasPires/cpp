#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define FORMS_COUNT 3

class Intern {
 public:
  Intern();
  Intern(Intern const &src);
  ~Intern();

  Intern &operator=(Intern const &rhs);

  AForm *makeForm(std::string formName, std::string target);

 private:
  AForm *buildShrubberyCreationForm(std::string const target);
  AForm *buildRobotomyRequestForm(std::string const target);
  AForm *buildPresidentialPardonForm(std::string const target);

  struct {
    std::string name;
    AForm *(Intern::*build)(std::string const);
  } _forms[FORMS_COUNT];
};

#endif
