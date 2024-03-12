#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:

	std::string const _name;
	bool _isSigned;
	int const _signGrade;
	int const _execGrade;

public:

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char * what(void) const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char * what(void) const throw();
	};

	class FormNotSignedException : public std::exception
	{
	public:
		virtual const char * what(void) const throw();
	};

	AForm(void);
	AForm(AForm const & src);
	AForm(std::string const & name, int const & signGrade, int const & execGrade);
	~AForm(void);
	AForm & operator=(AForm const & rhs);

	void beSigned(Bureaucrat const & b);
	void execute(Bureaucrat const & executor) const;
	virtual void performAction(std::string const & target) const = 0;

	std::string const & getName(void) const;
	bool const & getIsSigned(void) const;
	int const & getSignGrade(void) const;
	int const & getExecGrade(void) const;

	void setIsSigned(bool const & value);
};

std::ostream & operator<<(std::ostream & o, AForm const & f);

#endif