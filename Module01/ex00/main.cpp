#include <iostream>
#include "Zombie.hpp"

int main(void)
{
	Zombie joe = Zombie("Joe");
	Zombie* dina = newZombie("Dina");

	dina->announce();
	joe.announce();

	randomChump("Dontforgetme");

	joe.announce();
	dina->announce();

	delete dina;
}