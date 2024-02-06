#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

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
	Bureaucrat(int const grade, std::string const & name);
	~Bureaucrat(void);
	Bureaucrat & operator=(Bureaucrat const & rhs);

	void incGrade(void);
	void decGrade(void);

	std::string const & getName(void) const;
	int getGrade(void) const;
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & b);

#endif