#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5), _target("empty") {
  std::cout << "PresidentialPardonForm default constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target) {
  std::cout << "PresidentialPardonForm constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &src)
    : AForm("PresidentialPardonForm", 25, 5) {
  std::cout << "PresidentialPardonForm copy constructor called\n";
  *this = src;
}

PresidentialPardonForm::~PresidentialPardonForm() {
  std::cout << "PresidentialPardonForm destructor called\n";
}

PresidentialPardonForm &PresidentialPardonForm::operator=(
    PresidentialPardonForm const &rhs) {
  std::cout << "PresidentialPardonForm assignation operator called\n";

  if (this != &rhs) {
    const_cast<std::string &>(this->_target) = rhs.getTarget();
  }
  return *this;
}

std::string const PresidentialPardonForm::getTarget() const {
  return this->_target;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
  if (!this->getSigned() || executor.getGrade() > this->getGradeToExecute()) {
    throw AForm::GradeTooLowException();
  }

  std::cout << this->_target << " has been pardoned by Zafod Beeblebrox\n";
}
