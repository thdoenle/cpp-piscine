#include "Animal.hpp"
#include <iostream>

Animal::Animal(void) : _type("Animal")
{
	std::cout << "Animal default created" << std::endl;
}

Animal::Animal(Animal const & src) : _type(src.getType())
{
	std::cout << "Animal copy created" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal destroyed" << std::endl;
}

Animal & Animal::operator=(Animal const & rhs)
{
	_type = rhs.getType();
	return *this;
}

void Animal::makeSound(void) const
{
	std::cout << "NO SOUND" << std::endl;
}

std::string Animal::getType(void) const
{
	return _type;
}