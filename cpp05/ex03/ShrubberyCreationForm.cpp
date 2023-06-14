#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), _target("empty") {
  std::cout << "ShrubberyCreationForm default constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
  std::cout << "ShrubberyCreationForm constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
    : AForm("ShrubberyCreationForm", 145, 137) {
  std::cout << "ShrubberyCreationForm copy constructor called\n";
  *this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
  std::cout << "ShrubberyCreationForm destructor called\n";
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(
    ShrubberyCreationForm const &rhs) {
  if (this != &rhs) {
    const_cast<std::string &>(this->_target) = rhs.getTarget();
  }
  return *this;
}

std::string const ShrubberyCreationForm::getTarget() const {
  return this->_target;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  if (!this->getSigned() || executor.getGrade() > this->getGradeToExecute()) {
    throw AForm::GradeTooLowException();
  }

  std::ofstream file((this->_target + "_shrubbery").c_str());
  if (!file.is_open()) {
    std::cout << "Error: could not open file\n";
    return;
  }

  file << ASCII_TREE;
  file.close();
}
