#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(void) : _grade(150)
{
	std::cout << "Default Bureaucrat made" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _grade(src.getGrade())
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
}

Bureaucrat::Bureaucrat(int const grade)
{
	if (grade < 1)
		// ...
	// ...
}

void Bureaucrat::incGrade(void)
{
	// ...
}

std::string const & Bureaucrat::getName(void) const
{
	return _name;
}

int Bureaucrat::getGrade(void) const
{
	return _grade;
}