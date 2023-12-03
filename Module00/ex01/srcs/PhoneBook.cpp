#include <iostream>
#include <cstdlib>
#include "PhoneBook.hpp"
#include "utils.hpp"

PhoneBook::PhoneBook(void) : _curContact(0), _numContact(0) {}

PhoneBook::~PhoneBook(void) {}

bool PhoneBook::addNewContact(void)
{
	ut::printIn();
	std::cout << std::endl;
	std::cout << "Adding new contact." << std::endl;
	if (!_contacts[_curContact].setFromUserInput())
		return false;
	std::cout << "Contact added successfully!" << std::endl;
	if (_numContact == MAX_NUM_CONTACT - 1)
	{
		std::cout << "WARNING! The contact list is full." << std::endl;
		std::cout << "From now on, each call to ADD will" << std::endl;
		std::cout << "remove the oldest contact." << std::endl;
	}
	if (_numContact == MAX_NUM_CONTACT)
		std::cout << "Oldest contact removed." << std::endl;
	if (_numContact < MAX_NUM_CONTACT)
		_numContact++;
	_curContact++;
	if (_curContact == MAX_NUM_CONTACT)
		_curContact = 0;
	std::cout << std::endl;
	ut::printOut();
	return true;
}

int PhoneBook::askIndex(void) const
{
	std::string input;
	int			index = -1;

	while (index == -1)
	{
		if (!ut::askUser("contact index", input))
			return -1;
		if (!input.length())
			continue;
		if (ut::containsNonDigit(input))
			std::cout << "ERROR" << std::endl
				<< "non digit characters" << std::endl;
		else if (input.length() > 9)
			std::cout << "ERROR" << std::endl
				<< "too much digits" << std::endl;
		else
		{
			index = atoi(input.c_str()) - 1;
			if (index < 0 || index >= _numContact)
			{
				std::cout << "ERROR" << std::endl
					<< "index unavailable" << std::endl;
				index = -1;
			}
		}
	}
	return index;
}

bool PhoneBook::searchContact(void) const
{
	int index;

	if (_numContact == 0)
	{
		std::cout << "No contact registered." << std::endl;
		std::cout << "Add one using the ADD command." << std::endl;
		return true;
	}
	ut::printIn();
	/*if (_numContact == 1)
	{
		std::cout << "Only one contact:" << std::endl;
		_contacts[0].printFull();
		ut::printOut();
		return true;
	}*/
	printContacts();
	index = askIndex();
	if (index == -1)
		return false;
	if (_numContact == MAX_NUM_CONTACT)
		index = (index + _curContact) % MAX_NUM_CONTACT;
	_contacts[index].printFull();
	ut::printOut();
	return true;
}

void PhoneBook::printContacts(void) const
{
	std::cout << std::endl;
	for (int i = 0; i < 45; i++)
		std::cout << "=";
	std::cout << std::endl;
	if (_numContact == MAX_NUM_CONTACT)
	{
		for (int i = _curContact; i < MAX_NUM_CONTACT; i++)
			_contacts[i].printInline(i - _curContact + 1);
		for (int i = 0; i < _curContact; i++)
			_contacts[i].printInline(i - _curContact + 1 + MAX_NUM_CONTACT);
	}
	else
	{
		for (int i = 0; i < _numContact; i++)
			_contacts[i].printInline(i + 1);
	}
	for (int i = 0; i < 45; i++)
		std::cout << "=";
	std::cout << std::endl;
	std::cout << std::endl;
}