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

Bureaucrat::Bureaucrat(int const grade, std::string const & name) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
	std::cout << "Graded Bureaucrat made" << std::endl;
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
	return "ERROR: Grade is too high";
}

const char * Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "ERROR: Grade is too low";
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & b)
{
	o << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return o;
}