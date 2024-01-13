#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void) : _name(""), _hitPoints(10), _energyPoints(10),
	_attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string const & name) : _name(name), _hitPoints(10),
	_energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap name constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src) : _name(src.getName()),
	_hitPoints(src.getHitPoints()), _energyPoints(src.getEnergyPoints()),
	_attackDamage(src.getAttackDamage())
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs)
{
	_name = rhs.getName();
	_hitPoints = rhs.getHitPoints();
	_energyPoints = rhs.getEnergyPoints();
	_attackDamage = rhs.getAttackDamage();
	return *this;
}

void ClapTrap::attack(std::string const & target)
{
	if (!_hitPoints)
	{
		std::cout << "ClapTrap " << _name <<
			" is K.O., they're unable to attack!" << std::endl;
		return;
	}
	if (!_energyPoints)
	{
		std::cout << "ClapTrap " << _name << " is too tired to attack!"
			<< std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " attack " << target << ", causing "
		<< _attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!_hitPoints)
	{
		std::cout << "ClapTrap " << _name << " is K.O. already!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " hit points drop from " << _hitPoints;
	if (amount > _hitPoints)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	std::cout << " to " << _hitPoints << "!" << std::endl;
	if (!_hitPoints)
			std::cout << "ClapTrap " << _name << " got knocked out!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!_hitPoints)
	{
		std::cout << "ClapTrap " << _name
			<< " is K.O., they cannot repair themselves!" << std::endl;
		return;
	}
	if (!_energyPoints)
	{
		std::cout << "ClapTrap " << _name
			<< " is too tired to repair themselves!" << std::endl;
		return;
	}
	std::cout << "Clap Trap " << _name << " hit points increase from "
		<< _hitPoints;
	if (_hitPoints > amount + _hitPoints
		|| amount > amount + _hitPoints)
		_hitPoints = 4294967295U;
	else
		_hitPoints += amount;
	_energyPoints--;
	std::cout << " to " << _hitPoints << "!" << std::endl;
}

std::string ClapTrap::getName(void) const
{
	return _name;
}

unsigned int ClapTrap::getHitPoints(void) const
{
	return _hitPoints;
}

unsigned int ClapTrap::getEnergyPoints(void) const
{
	return _energyPoints;
}

unsigned int ClapTrap::getAttackDamage(void) const
{
	return _attackDamage;
}