#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("nobody", 25, 5)
{
	std::cout << "Default PPForm made" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src)
	: AForm(src)
{
	std::cout << "Copy PPForm made" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target)
	: AForm(target, 25, 5)
{
	std::cout << target << " PPForm made" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PPForm destroyed" << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	setIsSigned(rhs.getIsSigned());
	return *this;
}

void PresidentialPardonForm::performAction(std::string const & target) const
{
	std::cout << "!INFORMATION!" << std::endl;
	std::cout << "> " << target << " has been pardonned by Zaphod Beeblebrox." << std::endl;
}