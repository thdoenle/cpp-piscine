#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(void) : _grade(150), _name("Joe")
{
	std::cout << "Default Bureaucrat made" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _grade(src.getGrade()), _name(src.getName())
{
	std::cout << "Copy Bureaucrat made" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destroyed" << std::endl;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
	_grade = rhs.getGrade();
	return *this;
}

Bureaucrat::Bureaucrat(std::string const & name, int const grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
	std::cout << "Bureaucrat named " << _name << " made" << std::endl;
}

void Bureaucrat::incGrade(void)
{
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decGrade(void)
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(AForm & f) const
{
	if (f.getIsSigned())
	{
		std::cout << _name << " couldn't sign form " << f.getName()
			<< " because it's signed already." << std::endl;
		return;
	}
	try
	{
		f.beSigned(*this);
		std::cout << _name << " signed form " << f.getName() << "." << std::endl;
	}
	catch (std::exception const & e)
	{
		std::cout << _name << " couldn't sign form " << f.getName()
			<< " because their grade is too low." << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed form " << form.getName() << "." << std::endl;
	}
	catch (AForm::GradeTooLowException const & e)
	{
		std::cout << _name << " couldn't execute form " << form.getName()
			<< " because their grade is too low." << std::endl;
	}
	catch (AForm::FormNotSignedException const & e)
	{
		std::cout << _name << " couldn't execute form " << form.getName()
			<< " because it isn't signed." << std::endl;
	}
}

std::string const & Bureaucrat::getName(void) const
{
	return _name;
}

int Bureaucrat::getGrade(void) const
{
	return _grade;
}

const char * Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "BUREAUCRAT ERROR: Grade is too high";
}

const char * Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "BUREAUCRAT ERROR: Grade is too low";
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & b)
{
	o << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
	return o;
}