#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
public:

	PresidentialPardonForm(void);
	PresidentialPardonForm(PresidentialPardonForm const & src);
	PresidentialPardonForm(std::string const & target);
	~PresidentialPardonForm(void);
	PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs);

	void performAction(std::string const & target) const;
};

#endif