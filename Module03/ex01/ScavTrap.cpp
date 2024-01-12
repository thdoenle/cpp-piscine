#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void)// : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string const & name) : ClapTrap(name)
{
	std::cout << "ScavTrap name constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap(src)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs)
{
	_name = rhs.getName();
	_hitPoints = rhs.getHitPoints();
	_energyPoints = rhs.getEnergyPoints();
	_attackDamage = rhs.getAttackDamage();
	return *this;
}

void ScavTrap::attack(std::string const & target)
{
	if (!_hitPoints)
	{
		std::cout << "ScavTrap " << _name <<
			" is K.O., they're unable to attack!" << std::endl;
		return;
	}
	if (!_energyPoints)
	{
		std::cout << "ScavTrap " << _name << " is too tired to attack!"
			<< std::endl;
		return;
	}
	std::cout << "ScavTrap " << _name << " attack " << target << ", causing "
		<< _attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}