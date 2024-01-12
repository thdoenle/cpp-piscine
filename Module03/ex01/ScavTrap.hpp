#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap
{
public:

	ScavTrap(void);
	ScavTrap(std::string const & name);
	ScavTrap(ScavTrap const & src);
	~ScavTrap(void);
	ScavTrap & operator=(ScavTrap const & rhs);

	void attack(std::string const & target);
};

#endif