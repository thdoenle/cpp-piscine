#include "Form.hpp"

Form::Form(void)
{
	std::cout << "Default Form made" << std::endl;
}

Form::Form(Form const & src)
{
	std::cout << "Copy Form made" << std::endl;
}

Form::~Form(void)
{
}

Form & Form::operator=(Form const & rhs)
{
}