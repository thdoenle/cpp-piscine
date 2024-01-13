#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void clapTrapTests(void)
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

int main(void)
{
	clapTrapTests();

	std::cout << std::endl << "==================" << std::endl << std::endl;

    ScavTrap guard("Guard");
	ScavTrap guard2;
	guard2 = guard;
	ScavTrap guard3(guard);
	std::cout << std::endl;

	guard.attack("someone");
	guard.attack("someone else");
	guard.beRepaired(100);
	guard.guardGate();
	std::cout << std::endl;

	guard2.attack("foe");
	guard2.beRepaired(4000000000);
	guard2.beRepaired(1000000000);
	std::cout << std::endl;

	guard2.attack("invader");
	guard3.takeDamage(120);
	guard3.attack("");
	guard3.beRepaired(10);
	guard3.takeDamage(1);
	std::cout << std::endl;
}