#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal")
{
	std::cout << "WrongAnimal default created" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src) : _type(src.getType())
{
	std::cout << "WrongAnimal copy created" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destroyed" << std::endl;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & rhs)
{
	_type = rhs.getType();
	return *this;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "NO SOUND" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return _type;
}