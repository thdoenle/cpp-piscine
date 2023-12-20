#include "ClapTrap.hpp"
#include <iostream>

ClapTrap **		ClapTrap::_instances = NULL;
unsigned int	ClapTrap::_nbInstances = 0;

void ClapTrap::addToInstances(void) const
{
	ClapTrap ** instances;

	_nbInstances++;
	instances = new ClapTrap * [_nbInstances];
	for (unsigned int i = 0; i < _nbInstances - 1; i++)
		instances[i] = _instances[i];
	instances[_nbInstances - 1] = (ClapTrap *) this;
	delete [] _instances;
	_instances = instances;
}

void ClapTrap::removeFromInstances(void) const
{
	ClapTrap ** 	instances = NULL;
	unsigned int	offset = 0;

	_nbInstances--;
	if (_nbInstances)
		instances = new ClapTrap * [_nbInstances];
	for (unsigned int i = 0; i < _nbInstances; i++)
	{
		if (_instances[i] == this)
			offset = 1;
		else
			instances[i] = _instances[i + offset];
	}
	delete [] _instances;
	_instances = instances;
}

ClapTrap * ClapTrap::findByName(std::string const & name) const
{
	for (unsigned int i = 0; i < _nbInstances; i++)
		if (name == _instances[i]->getName())
			return _instances[i];
	return NULL;
}

ClapTrap::ClapTrap(void) : _name(""), _hitPoints(10), _energyPoints(10),
	_attackDamage(0)
{
	std::cout << "Default constructor called" << std::endl;
	addToInstances();
}

ClapTrap::ClapTrap(std::string const & name) : _name(name), _hitPoints(10),
	_energyPoints(10), _attackDamage(0)
{
	std::cout << "Name constructor called" << std::endl;
	addToInstances();
}

ClapTrap::ClapTrap(ClapTrap const & src) : _name(src.getName()),
	_hitPoints(src.getHitPoints()), _energyPoints(src.getEnergyPoints()),
	_attackDamage(src.getAttackDamage())
{
	std::cout << "Copy constructor called" << std::endl;
	addToInstances();
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
	removeFromInstances();
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

	ClapTrap * targetInst = findByName(target);

	if (!targetInst)
	{
		std::cout << "No ClapTrap named " << target << "!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " attack " << target << ", causing "
		<< _attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
	targetInst->takeDamage(_attackDamage);
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
			<< " is to tired to repair themselves!" << std::endl;
		return;
	}
	std::cout << "Clap Trap " << _name << " hit points increase from "
		<< _hitPoints;
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