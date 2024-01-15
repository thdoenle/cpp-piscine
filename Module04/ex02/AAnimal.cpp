#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal(void) : _type("AAnimal")
{
	std::cout << "AAnimal default created" << std::endl;
}

AAnimal::AAnimal(AAnimal const & src) : _type(src.getType())
{
	std::cout << "AAnimal copy created" << std::endl;
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal destroyed" << std::endl;
}

AAnimal & AAnimal::operator=(AAnimal const & rhs)
{
	_type = rhs.getType();
	return *this;
}

std::string AAnimal::getType(void) const
{
	return _type;
}