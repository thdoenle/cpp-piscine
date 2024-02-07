#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form(void) : _name("Default"), _isSigned(false), _signGrade(150), _execGrade(150)
{
	std::cout << "Default Form made" << std::endl;
}

Form::Form(Form const & src) : _name(src.getName()), _isSigned(src.getIsSigned()),
	_signGrade(src.getSignGrade()), _execGrade(src.getExecGrade())
{
	std::cout << "Copy Form made" << std::endl;
}

Form::Form(std::string const & name, int const & signGrade, int const & execGrade)
	: _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	std::cout << "Form named " << _name << " made" << std::endl;
}

Form::~Form(void)
{
	std::cout << "Form destroyed" << std::endl;
}

Form & Form::operator=(Form const & rhs)
{
	_isSigned = rhs.getIsSigned();
	return *this;
}

void Form::beSigned(Bureaucrat const & b)
{
	if (b.getGrade() > _signGrade)
		throw GradeTooLowException();
	_isSigned = true;
}

std::string const & Form::getName(void) const
{
	return _name;
}

bool const & Form::getIsSigned(void) const
{
	return _isSigned;
}

int const & Form::getSignGrade(void) const
{
	return _signGrade;
}

int const & Form::getExecGrade(void) const
{
	return _execGrade;
}

const char * Form::GradeTooHighException::what(void) const throw()
{
	return "FORM ERROR: Grade is too high";
}

const char * Form::GradeTooLowException::what(void) const throw()
{
	return "FORM ERROR: Grade is too low";
}

std::ostream & operator<<(std::ostream & o, Form const & f)
{
	o << "Form " << f.getName() << " (required grades: " << f.getSignGrade()
		<< " to sign, " << f.getExecGrade() << " to execute), "
		<< (f.getIsSigned() ? "" : "not") << " signed." << std::endl;
	return o;
}