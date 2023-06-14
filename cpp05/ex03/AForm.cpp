#include "AForm.hpp"

AForm::AForm()
    : _isSigned(false), _name("default"), _gradeToSign(1), _gradeToExecute(1) {
  std::cout << "AForm default constructor called\n";
}

AForm::AForm(std::string const name, int const gradeToSign,
             int const gradeToExecute)
    : _isSigned(false),
      _name(name),
      _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute) {
  std::cout << "AForm constructor called\n";
}

AForm::AForm(AForm const &src) : _gradeToSign(1), _gradeToExecute(1) {
  std::cout << "AForm copy constructor called\n";
  *this = src;
}

AForm::~AForm() { std::cout << "AForm destructor called\n"; }

AForm &AForm::operator=(AForm const &rhs) {
  if (this != &rhs) {
    this->_isSigned = rhs.getSigned();
    const_cast<std::string &>(this->_name) = rhs.getName();
    const_cast<int &>(this->_gradeToSign) = rhs.getGradeToSign();
    const_cast<int &>(this->_gradeToExecute) = rhs.getGradeToExecute();
  }
  return *this;
}

std::string const AForm::getName() const { return this->_name; }

int AForm::getGradeToSign() const { return this->_gradeToSign; }
int AForm::getGradeToExecute() const { return this->_gradeToExecute; }
bool AForm::getSigned() const { return this->_isSigned; }

void AForm::beSigned(Bureaucrat const &bureaucrat) {
  if (bureaucrat.getGrade() > this->_gradeToSign) {
    throw AForm::GradeTooLowException();
  }
  this->_isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
  return "Grade too high";
}
const char *AForm::GradeTooLowException::what() const throw() {
  return "Grade too low";
}
