#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:

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

	std::string const _name;
	bool _isSigned;
	int const _signGrade;
	int const _execGrade;

public:

	Form(void);
	Form(Form const & src);
	Form(std::string const & name, int const & signGrade, int const & execGrade);
	~Form(void);
	Form & operator=(Form const & rhs);

	void beSigned(Bureaucrat const & b);

	std::string const & getName(void) const;
	bool const & getIsSigned(void) const;
	int const & getSignGrade(void) const;
	int const & getExecGrade(void) const;
};

std::ostream & operator<<(std::ostream & o, Form const & f);

#endif