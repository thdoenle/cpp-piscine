#include <iostream>
#include "Harl.hpp"

/*HarlMemberFn Harl::_f[4] = {
	&Harl::debug, 
	&Harl::info,
	&Harl::warning,
	&Harl::error
};*/

HarlMemberFn Harl::_f = &Harl::debug;

std::string Harl::_levels[4] = {
	"DEBUG",
	"INFO",
	"WARNING",
	"ERROR"
};

Harl::Harl(void)
{
	std::cout << "Harl created" << std::endl;
}

Harl::~Harl(void)
{
	std::cout << "Harl destroyed" << std::endl;
}

void Harl::debug(void) const
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my \
7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl;
	std::cout << "I really do!" << std::endl << std::endl;
}

void Harl::info(void) const
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn't put enough bacon in my burger!" << std::endl;
	std::cout << "If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void Harl::warning(void) const
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I've been coming for years whereas you started working here \
since last month." << std::endl << std::endl;
}

void Harl::error(void) const
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable!" << std::endl;
	std::cout << "I want to speak to the manager now." << std::endl << std::endl;
}

void Harl::complain(std::string level) const
{
	for (int i = 0; i < 4; i++)
		if (level == _levels[i])
			(*_f)();
}