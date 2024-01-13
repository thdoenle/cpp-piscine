#include "WrongDog.hpp"
#include <iostream>

WrongDog::WrongDog(void)
{
	_type = "WrongDog";
	std::cout << "WrongDog default created" << std::endl;
}

WrongDog::WrongDog(WrongDog const & src) : WrongAnimal(src)
{
	std::cout << "WrongDog copy created" << std::endl;
}

WrongDog::~WrongDog(void)
{
	std::cout << "WrongDog destroyed" << std::endl;
}

WrongDog & WrongDog::operator=(WrongDog const & rhs)
{
	_type = rhs.getType();
	return *this;
}

void WrongDog::makeSound(void) const
{
	std::cout << "Woof!" << std::endl;
}