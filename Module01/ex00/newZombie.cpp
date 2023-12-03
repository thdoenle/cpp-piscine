#include "Zombie.hpp"
#include <string>

Zombie* newZombie(std::string const name)
{
	return new Zombie(name);
}