#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>

#define MAX_GRADE 1
#define MIN_GRADE 150

#include "AForm.hpp"

class AForm;
class Bureaucrat
{
public:
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	Bureaucrat();
	Bureaucrat(std::string const &name, int grade);
	Bureaucrat(Bureaucrat const &src);
	~Bureaucrat();

	Bureaucrat &operator=(Bureaucrat const &rhs);

	std::string getName() const;
	int getGrade() const;


	void setGrade(int grade);

	void incrementGrade();
	void decrementGrade();
	void signForm(AForm &form);

	void executeForm(AForm const &form);

private:
	int _grade;
	std::string const _name;
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &self);

#endif
