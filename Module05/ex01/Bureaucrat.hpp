#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
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

	int _grade;
	std::string const _name;

public:

	Bureaucrat(void);
	Bureaucrat(Bureaucrat const & src);
	Bureaucrat(std::string const & name, int const grade);
	~Bureaucrat(void);
	Bureaucrat & operator=(Bureaucrat const & rhs);

	void incGrade(void);
	void decGrade(void);
	void signForm(Form & f) const;

	std::string const & getName(void) const;
	int getGrade(void) const;
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & b);

#endif