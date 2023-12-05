#include <iostream>
#include "Zombie.hpp"

int main(void)
{
	Zombie* walkers = zombieHorde(1, "Walker");
	Zombie* error = zombieHorde(-42, "lol");
	Zombie* fatties = zombieHorde(2, "Fatty");

	// print all Walker
	walkers->announce();

	delete [] walkers;

	Zombie* runners = zombieHorde(5, "Runner");

	// print all Fatty
	for (int i = 0; i < 2; i++)
		fatties[i].announce();
	
	// print all Runner
	for (int i = 0; i < 5; i++)
		runners[i].announce();

	delete [] fatties;
	delete [] runners;
	delete [] error;
}