#include "Form.hpp"

Form::Form()
    : _isSigned(false),
      _name("default"),
      _gradeToSign(42),
      _gradeToExecute(42) {
  std::cout << "Form default constructor called\n";
}

Form::Form(std::string const name, int const gradeToSign,
           int const gradeToExecute)
    : _isSigned(false),
      _name(name),
      _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute) {
  std::cout << "Form constructor called\n";
  if (gradeToSign < 1 || gradeToExecute < 1) {
    throw Form::GradeTooHighException();
  } else if (gradeToSign > 150 || gradeToExecute > 150) {
    throw Form::GradeTooLowException();
  }
}

Form::Form(Form const &src) : _gradeToSign(1), _gradeToExecute(1) {
  std::cout << "Form copy constructor called\n";
  *this = src;
}

Form::~Form() { std::cout << "Form destructor called\n"; }

Form &Form::operator=(Form const &rhs) {
  if (this != &rhs) {
    this->_isSigned = rhs.getSigned();
    const_cast<std::string &>(this->_name) = rhs.getName();
    const_cast<int &>(this->_gradeToSign) = rhs.getGradeToSign();
    const_cast<int &>(this->_gradeToExecute) = rhs.getGradeToExecute();
  }
  return *this;
}

std::string const Form::getName() const { return this->_name; }
int Form::getGradeToSign() const { return this->_gradeToSign; }
int Form::getGradeToExecute() const { return this->_gradeToExecute; }
bool Form::getSigned() const { return this->_isSigned; }

void Form::beSigned(Bureaucrat const &bureaucrat) {
  if (bureaucrat.getGrade() > this->_gradeToSign) {
    throw Form::GradeTooLowException();
  }

  this->_isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw() {
  return "Grade too high";
}
const char *Form::GradeTooLowException::what() const throw() {
  return "Grade too low";
}

std::ostream &operator<<(std::ostream &out, Form const &self) {
  out << self.getName() << ", form grade to sign: " << self.getGradeToSign()
      << ", form grade to execute: " << self.getGradeToExecute()
      << ", form is signed: " << self.getSigned();
  return out;
}
