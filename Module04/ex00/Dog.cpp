#include "Dog.hpp"
#include <iostream>

Dog::Dog(void)
{
	_type = "Dog";
	std::cout << "Dog default created" << std::endl;
}

Dog::Dog(Dog const & src) : Animal(src)
{
	std::cout << "Dog copy created" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Dog destroyed" << std::endl;
}

Dog & Dog::operator=(Dog const & rhs)
{
	_type = rhs.getType();
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "Woof!" << std::endl;
}