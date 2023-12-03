#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "utils.hpp"
#include <iostream>

void printCmdError(std::string cmd)
{
	bool hasBadFormat = false;
	bool hasSpace = false;

	std::cout << "ERROR" << std::endl;
	if (cmd == "")
		std::cout << "no command entered" << std::endl;
	else
	{
		for (size_t i = 0; i < cmd.size(); i++)
		{
			if (isspace(cmd[i]))
			{
				hasSpace = true;
				break;
			}
			if (!isalpha(cmd[i]) || !isupper(cmd[i]))
				hasBadFormat = true;
		}
		if (hasSpace)
			std::cout << "several words entered" << std::endl;
		if (hasBadFormat)
			std::cout << "bad format (uppercase letters only)" << std::endl;
		if (!hasBadFormat && !hasSpace)
			std::cout << "unknown command" << std::endl;
	}
	ut::printIn();
	std::cout << std::endl;
	std::cout << "The available commands are:" << std::endl;
	std::cout << "ADD -> add a contact" << std::endl;
	std::cout << "SEARCH -> ask for a contact and print it" << std::endl;
	std::cout << "EXIT -> quit the program" << std::endl;
	std::cout << std::endl;
	ut::printOut();
}

int main(void)
{
	PhoneBook	phoneBook;
	std::string	cmd;

	while (ut::askUser("a command", cmd) && cmd != "EXIT")
	{
		if (cmd == "ADD")
		{
			if (phoneBook.addNewContact() == false)
				break;
		}
		else if (cmd == "SEARCH")
		{
			if (phoneBook.searchContact() == false)
				break;
		}
		else
			printCmdError(cmd);
	}
	if (std::cin.bad())
		std::cout << "cin badbit set" << std::endl;
	else if (std::cin.eof())
		std::cout << "reached EOF (Ctrl-D)" << std::endl;
	else
		std::cout << "Program quit. The contacts are gone forever!!" << std::endl;
}