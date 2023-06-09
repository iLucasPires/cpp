#ifndef AAFORM_HPP
#define AAFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
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

	AForm();
	AForm(std::string const name, int const gradeToSign, int const gradeToExecute);
	AForm(AForm const &src);
	AForm &operator=(AForm const &rhs);

	std::string const getName() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	bool getSigned() const;

	void beSigned(Bureaucrat const &bureaucrat);
	virtual ~AForm() = 0;
	virtual void execute(Bureaucrat const &executor) const = 0;


private:
	bool _isSigned;
	std::string const _name;
	int const _gradeToSign;
	int const _gradeToExecute;
};

#endif
