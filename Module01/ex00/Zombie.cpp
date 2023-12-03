#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(std::string const name) : _name(name)
{
	std::cout << "[Zombie " << _name << " came back from the afterlife!]" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "[Zombie " << _name << " returned to dust.]" << std::endl;
}

void Zombie::announce(void) const
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}