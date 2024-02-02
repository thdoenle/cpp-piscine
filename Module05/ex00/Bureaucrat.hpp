#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

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

	std::string const _name = "Joe the Bureaucrat";
	int _grade;

public:

	Bureaucrat(void);
	Bureaucrat(Bureaucrat const & src);
	~Bureaucrat(void);
	Bureaucrat & operator=(Bureaucrat const & rhs);

	void incGrade(void);
	void decGrade(void);

	std::string const & getName(void) const;
	int getGrade(void) const;
};

#endif