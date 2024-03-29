#include <iostream>
#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap shinobi("Shinobi");
	ClapTrap shinobi2;
	shinobi2 = shinobi;
	ClapTrap shinobi3(shinobi);
	std::cout << std::endl;

	shinobi.attack("Someone");
	shinobi.attack("Someone else");
	shinobi.beRepaired(10);
	std::cout << std::endl;

	shinobi2.beRepaired(4000000000);
	shinobi2.beRepaired(1000000000);
	std::cout << std::endl;

	shinobi3.takeDamage(12);
	shinobi3.attack("");
	shinobi3.beRepaired(10);
	shinobi3.takeDamage(1);
	std::cout << std::endl;
}