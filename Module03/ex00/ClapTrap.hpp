#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <string>

class ClapTrap
{
private:

	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;

public:

	ClapTrap(void);
	ClapTrap(std::string const & name);
	ClapTrap(ClapTrap const & src);
	~ClapTrap(void);
	ClapTrap & operator=(ClapTrap const & rhs);

	void attack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	std::string		getName(void) const;
	unsigned int	getHitPoints(void) const;
	unsigned int	getEnergyPoints(void) const;
	unsigned int	getAttackDamage(void) const;
};

#endif