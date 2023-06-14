#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(42) {
  std::cout << "Bureaucrat default constructor called\n";
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade) {
  if (grade < 1) {
    throw Bureaucrat::GradeTooHighException();
  } else if (grade > 150) {
    throw Bureaucrat::GradeTooLowException();
  }
  std::cout << "Bureaucrat constructor called\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) {
  std::cout << "Bureaucrat copy constructor called\n";
  *this = src;
}

Bureaucrat::~Bureaucrat() { std::cout << "Bureaucrat destructor called\n"; }

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs) {
  if (this != &rhs) {
    this->_grade = rhs.getGrade();
    const_cast<std::string &>(this->_name) = rhs.getName();
  }
  return *this;
}

std::string Bureaucrat::getName() const { return this->_name; }

int Bureaucrat::getGrade() const { return this->_grade; }

void Bureaucrat::incrementGrade() {
  if (this->_grade > 1) {
    --this->_grade;
  } else {
    throw Bureaucrat::GradeTooHighException();
  }
}

void Bureaucrat::decrementGrade() {
  if (this->_grade < 150) {
    ++this->_grade;
  } else {
    throw Bureaucrat::GradeTooLowException();
  }
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade too low";
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &self) {
  out << self.getName() << ", bureaucrat grade " << self.getGrade();
  return out;
}
