#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
class Bureaucrat;
class Form {
 public:
  class GradeTooHighException : public std::exception {
   public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    virtual const char *what() const throw();
  };

  Form();
  Form(std::string const name, int const gradeToSign, int const gradeToExecute);

  Form(Form const &src);
  Form &operator=(Form const &rhs);

  ~Form();

  std::string const getName() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;
  bool getSigned() const;

  void beSigned(Bureaucrat const &bureaucrat);

 private:
  bool _isSigned;
  std::string const _name;
  int const _gradeToSign;
  int const _gradeToExecute;
};

std::ostream &operator<<(std::ostream &out, Form const &self);

#endif
