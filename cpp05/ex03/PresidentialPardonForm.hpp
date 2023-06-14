#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
 public:
  PresidentialPardonForm();
  PresidentialPardonForm(std::string const target);
  PresidentialPardonForm(PresidentialPardonForm const &src);
  ~PresidentialPardonForm();

  PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);

  std::string const getTarget() const;

  void execute(Bureaucrat const &executor) const;

 private:
  std::string const _target;
};
#endif
