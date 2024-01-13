#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void)
{
	_type = "WrongCat";
	std::cout << "WrongCat default created" << std::endl;
}

WrongCat::WrongCat(WrongCat const & src) : WrongAnimal(src)
{
	std::cout << "WrongCat copy created" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destroyed" << std::endl;
}

WrongCat & WrongCat::operator=(WrongCat const & rhs)
{
	_type = rhs.getType();
	return *this;
}

void WrongCat::makeSound(void) const
{
	std::cout << "Meeoooow..." << std::endl;
}