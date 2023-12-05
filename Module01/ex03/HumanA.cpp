#include "Weapon.hpp"
#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(char const name[], Weapon& weapon) : _name(name), _weapon(weapon)
{
	std::cout << ">>> HumanA named '" << name << "' with weapon type '"
		<< weapon.getType() << "' created" << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << ">>> HumanA named '" << _name << "' with weapon type '"
		<< _weapon.getType() << "' destroyed" << std::endl;
}

void HumanA::attack(void) const
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}