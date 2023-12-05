#include <iostream>
#include "Zombie.hpp"

int Zombie::_nbInst = 0;

Zombie::Zombie(std::string const name) : _name(name), _index(_nbInst)
{
	std::cout << "[Zombie " << _name
		<< "(index " << _index << ") came back from the afterlife!]" << std::endl;
	_nbInst++;
}

Zombie::Zombie() : _name("NO_NAME"), _index(_nbInst)
{
	std::cout << "[An unnamed zombie (index "
		<< _index << ") came back from the afterlife!]" << std::endl;
	_nbInst++;
}

Zombie::~Zombie(void)
{
	std::cout << "[Zombie " << _name << " (index " << _index
		<< ") returned to dust.]" << std::endl;
}

void Zombie::setName(std::string const name)
{
	_name = name;
	std::cout << "[Zombie " << _index << " name set to " << name << "]" << std::endl;
}

void Zombie::announce(void) const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}