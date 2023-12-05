#include <iostream>
#include "Zombie.hpp"

Zombie* zombieHorde(int const N, std::string const name)
{
	Zombie* horde;
	
	if (N <= 0)
	{
		std::cout << "Cannot make " << N << " zombies; "
			<< "zombies were not allocated." << std::endl;
		return NULL;
	}
	horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		horde[i].setName(name);
	return horde;
}