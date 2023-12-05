#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include "Weapon.hpp"
#include <string>

class HumanA
{
private:

	std::string	_name;
	Weapon&		_weapon;

public:

	HumanA(char const name[], Weapon& weapon);
	~HumanA(void);
	void attack(void) const;
};

#endif