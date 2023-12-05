#include "Weapon.hpp"
#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(char const name[]) : _name(name), _weapon(NULL)
{
	std::cout << ">>> HumanB named '" << name << "' with no weapon created" << std::endl;
}

HumanB::~HumanB(void)
{
	if (!_weapon)
		std::cout << ">>> HumanB named '" << _name
			<< "' with no weapon destroyed" << std::endl;
	else
		std::cout << ">>> HumanB named '" << _name << "' with weapon type '"
			<< _weapon->getType() << "' destroyed" << std::endl;
}

void HumanB::attack(void) const
{
	if (!_weapon)
		std::cout << _name << " has no weapon" << std::endl;
	else
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
	std::cout << ">>> HumanB named '" << _name << "' weapon set to '"
		<< _weapon->getType() << "'" << std::endl;
}