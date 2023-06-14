#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>

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
  Bureaucrat(std::string const name, int grade);

  Bureaucrat(Bureaucrat const &src);
  ~Bureaucrat();

  Bureaucrat &operator=(Bureaucrat const &rhs);

  std::string getName() const;
  int getGrade() const;

  void incrementGrade();
  void decrementGrade();

 private:
  std::string const _name;
  int _grade;
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &self);

#endif
