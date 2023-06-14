#include "Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade too high";
}
const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade too low";
}

Bureaucrat::Bureaucrat() : _grade(42), _name("default") {
  std::cout << "Bureaucrat default constructor called\n";
}

Bureaucrat::Bureaucrat(std::string const &name, int grade)
    : _grade(grade), _name(name) {
  std::cout << "Bureaucrat constructor called\n";
  if (grade < MAX_GRADE)
    throw Bureaucrat::GradeTooHighException();
  else if (grade > MIN_GRADE)
    throw Bureaucrat::GradeTooLowException();
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

void Bureaucrat::incrementGrade() {
  if (this->_grade < MAX_GRADE) {
    throw Bureaucrat::GradeTooHighException();
  }
  this->_grade--;
}

void Bureaucrat::decrementGrade() {
  if (this->_grade > MIN_GRADE) {
    throw Bureaucrat::GradeTooLowException();
  }
  this->_grade++;
}

void Bureaucrat::signForm(AForm &form) {
  try {
    form.beSigned(*this);
    std::cout << this->_name << " signs " << form.getName() << '\n';
  } catch (const std::exception &e) {
    std::cout << this->_name << " cannot sign " << form.getName() << " because "
              << e.what() << '\n';
  }
}

int Bureaucrat::getGrade() const { return this->_grade; }

std::string Bureaucrat::getName() const { return this->_name; }

void Bureaucrat::setGrade(int grade) {
  if (grade < MAX_GRADE)
    throw Bureaucrat::GradeTooHighException();
  else if (grade > MIN_GRADE)
    throw Bureaucrat::GradeTooLowException();
  this->_grade = grade;
}

void Bureaucrat::executeForm(AForm const &form) {
  std::cout << '[' << this->_name << "] tries to execute"
            << form.getName() << "\n";
  try {
    form.execute(*this);
    std::cout << "\33[32msuccessfully executed\33[0m\n";
  } catch (const std::exception &e) {
    std::cout << "\33[31mfailed to execute because " << e.what() << "\33[0m\n";
  }
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &self) {
  out << self.getName() << ", bureaucrat grade " << self.getGrade();
  return out;
}
