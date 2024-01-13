#include "Cat.hpp"
#include <iostream>

Cat::Cat(void)
{
	_type = "Cat";
	std::cout << "Cat default created" << std::endl;
}

Cat::Cat(Cat const & src) : Animal(src)
{
	std::cout << "Cat copy created" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Cat destroyed" << std::endl;
}

Cat & Cat::operator=(Cat const & rhs)
{
	_type = rhs.getType();
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "Meeoooow..." << std::endl;
}