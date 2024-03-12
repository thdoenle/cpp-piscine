#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm(void) : _name("Default"), _isSigned(false), _signGrade(150), _execGrade(150)
{
	std::cout << "Default AForm made" << std::endl;
}

AForm::AForm(AForm const & src) : _name(src.getName()), _isSigned(src.getIsSigned()),
	_signGrade(src.getSignGrade()), _execGrade(src.getExecGrade())
{
	std::cout << "Copy AForm made" << std::endl;
}

AForm::AForm(std::string const & name, int const & signGrade, int const & execGrade)
	: _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	std::cout << "AForm named " << _name << " made" << std::endl;
}

AForm::~AForm(void)
{
	std::cout << "AForm destroyed" << std::endl;
}

AForm & AForm::operator=(AForm const & rhs)
{
	_isSigned = rhs.getIsSigned();
	return *this;
}

void AForm::beSigned(Bureaucrat const & b)
{
	if (b.getGrade() > _signGrade)
		throw GradeTooLowException();
	_isSigned = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (!_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > _execGrade)
		throw GradeTooLowException();
	performAction(_name);
}

std::string const & AForm::getName(void) const
{
	return _name;
}

bool const & AForm::getIsSigned(void) const
{
	return _isSigned;
}

int const & AForm::getSignGrade(void) const
{
	return _signGrade;
}

int const & AForm::getExecGrade(void) const
{
	return _execGrade;
}

void AForm::setIsSigned(bool const & value)
{
	_isSigned = value;
}

const char * AForm::GradeTooHighException::what(void) const throw()
{
	return "FORM ERROR: Grade is too high";
}

const char * AForm::GradeTooLowException::what(void) const throw()
{
	return "FORM ERROR: Grade is too low";
}

const char * AForm::FormNotSignedException::what(void) const throw()
{
	return "FORM ERROR: Form is not signed";
}

std::ostream & operator<<(std::ostream & o, AForm const & f)
{
	o << "AForm " << f.getName() << " (required grades: " << f.getSignGrade()
		<< " to sign, " << f.getExecGrade() << " to execute), "
		<< (f.getIsSigned() ? "" : "not") << " signed." << std::endl;
	return o;
}