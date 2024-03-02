#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
public:

	RobotomyRequestForm(void);
	RobotomyRequestForm(RobotomyRequestForm const & src);
	RobotomyRequestForm(std::string const & target);
	~RobotomyRequestForm(void);
	RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);

	void performAction(std::string const & target) const;
};

#endif