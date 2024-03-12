#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Nobody", 72, 45)
{
	std::cout << "Default RRForm made" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src)
	: AForm(src)
{
	std::cout << "Copy RRForm made" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target)
	: AForm(target, 72, 45)
{
	std::cout << target << " RRForm made" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RRForm destroyed" << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	setIsSigned(rhs.getIsSigned());
	return *this;
}

void RobotomyRequestForm::performAction(std::string const & target) const
{
	std::cout << "* DrRrr... *" << std::endl;
	srand(time(NULL));
	if (rand() % 2)
		std::cout << "> Phew! " << target << "'s robotomization succeeded!" << std::endl;
	else
	{
		std::cout << "> Oops..! It seems robotomization failed..." << std::endl;
		std::cout << "> Sorry for the inconvenience " << target << "!" << std::endl;
	}
}