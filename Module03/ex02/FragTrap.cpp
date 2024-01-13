#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string const & name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap name constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const & src) : ClapTrap(src)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & rhs)
{
	_name = rhs.getName();
	_hitPoints = rhs.getHitPoints();
	_energyPoints = rhs.getEnergyPoints();
	_attackDamage = rhs.getAttackDamage();
	return *this;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name;
	if (!_hitPoints || !_energyPoints)
		std::cout << " cannot high fives.";
	else
		std::cout << " says: << Guys! Let's do a high fives!! >>";
	std::cout << std::endl;
}