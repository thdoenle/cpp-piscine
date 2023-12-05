#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon(void) : _type("NO_TYPE")
{
	std::cout << ">>> New no type weapon created" << std::endl;
}

Weapon::Weapon(std::string const & type) : _type(type)
{
	std::cout << ">>> New '" << type << "' weapon created" << std::endl;
}

Weapon::Weapon(char const type[]) : _type(type)
{
	std::cout << ">>> New '" << type << "' weapon created" << std::endl;
}

Weapon::~Weapon(void)
{
	std::cout << ">>> '" << _type << "' type weapon destroyed" << std::endl;
}

std::string const & Weapon::getType(void) const
{
	return _type;
}

void Weapon::setType(char const type[])
{
	std::cout << ">>> Changed weapon type from '" << _type;
	_type = type;
	std::cout << "' to '" << _type << "'" << std::endl;
}