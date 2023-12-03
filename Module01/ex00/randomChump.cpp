#include "Zombie.hpp"
#include <string>

void randomChump(std::string const name)
{
	Zombie zombie = Zombie(name);

	zombie.announce();
}