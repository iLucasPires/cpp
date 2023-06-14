#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>

#define MAX_GRADE 1
#define MIN_GRADE 150

#include "Form.hpp"

class Form;
class Bureaucrat {
 public:
  class GradeTooHighException : public std::exception {
   public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    virtual const char *what() const throw();
  };


  Bureaucrat();
  Bureaucrat(std::string const &name, int grade);

  Bureaucrat(Bureaucrat const &src);
  Bureaucrat &operator=(Bureaucrat const &rhs);

  ~Bureaucrat();

  std::string getName() const;
  int getGrade() const;
  void setGrade(int grade);

  void incrementGrade();
  void decrementGrade();
  void signForm(Form &form);

 private:
  std::string const _name;
  int _grade;
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &self);

#endif
