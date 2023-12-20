#include <iostream>
#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap shinobi("Shinobi");
	ClapTrap ninja = ClapTrap("Ninja");

	ninja.attack("Shinobi");
	ninja.takeDamage(4);
	ninja.attack("Samourai");

	ClapTrap samourai("Samourai");

	samourai.attack("Ninja");
	ninja.takeDamage(4);
	ninja.beRepaired(1);
	for (int i = 0; i < 11; i++)
		shinobi.attack("Samourai");
	shinobi.beRepaired(1);
	ninja.takeDamage(4);
	ninja.attack("");
	ninja.beRepaired(10);
}