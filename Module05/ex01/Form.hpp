#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Form
{
private:

	std::string const _name;

public:

	Form(void);
	Form(Form const & src);
	~Form(void);
	Form & operator=(Form const & rhs);
};

#endif