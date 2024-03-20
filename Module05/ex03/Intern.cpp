#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

InternNewFormFn Intern::_newFormFns[3] = {
	&Intern::newSCForm,
	&Intern::newRRForm,
	&Intern::newPPForm
};

std::string Intern::_formNames[3] = {
	"shrubbery creation",
	"robotomy request",
	"presidential pardon"
};

Intern::Intern(void)
{
	std::cout << "Default Intern made" << std::endl;
}

Intern::Intern(Intern const & src)
{
	(void)src;
	std::cout << "Copy Intern made" << std::endl;
}

Intern::~Intern(void)
{
	std::cout << "Intern destroyed" << std::endl;
}

Intern & Intern::operator=(Intern const & rhs)
{
	(void)rhs;
	return *this;
}

AForm * Intern::newSCForm(std::string const & target) const
{
	return new ShrubberyCreationForm(target);
}

AForm * Intern::newRRForm(std::string const & target) const
{
	return new RobotomyRequestForm(target);
}

AForm * Intern::newPPForm(std::string const & target) const
{
	return new PresidentialPardonForm(target);
}

AForm * Intern::makeForm(std::string name, std::string const & target) const
{
	AForm * form = NULL;

	for (size_t i = 0; i < name.length(); i++)
		name[i] = tolower(name[i]);

	for (int i = 0; i < 3; i++)
		if (name == _formNames[i])
			form = (this->*_newFormFns[i])(target);
	
	if (form)
		std::cout << "Intern creates " << name << "." << std::endl;
	else
		std::cout << "Intern cannot create " << name
			<< " because it doesn't exist." << std::endl;

	return form;
}