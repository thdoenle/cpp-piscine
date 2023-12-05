#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include "Weapon.hpp"
#include <string>

class HumanB
{
private:

	std::string	_name;
	Weapon*		_weapon;

public:

	HumanB(char const name[]);
	~HumanB(void);
	void attack(void) const;
	void setWeapon(Weapon& weapon);
};

#endif