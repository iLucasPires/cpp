#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <stdlib.h>

class RobotomyRequestForm : public AForm
{

public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string const target);
	RobotomyRequestForm(RobotomyRequestForm const &src);
	~RobotomyRequestForm();

	RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);

	std::string const getTarget() const;

	void execute(Bureaucrat const &executor) const;
private:
	std::string const _target;
};

#endif
