#include <iostream>
#include "Contact.hpp"
#include "utils.hpp"

Contact::Contact(void) {}

Contact::~Contact(void) {}

void Contact::formatName(std::string &name) const
{
	name[0] = toupper(name[0]);
	for (size_t i = 1; i < name.length(); i++)
		name[i] = tolower(name[i]);
}

bool Contact::setFromUserInput(void)
{
	_firstName = "";
	while (_firstName == "")
	{
		if (!ut::askUser("first name", _firstName))
			return false;
		if (ut::containsNonAlpha(_firstName))
		{
			std::cout << "ERROR" << std::endl
				<< "non-alpha characters" << std::endl;
			_firstName = "";
		}
	}
	formatName(_firstName);

	_lastName = "";
	while (_lastName == "")
	{
		if (!ut::askUser("last name", _lastName))
			return false;
		if (ut::containsNonAlpha(_lastName))
		{
			std::cout << "ERROR" << std::endl
				<< "non-alpha characters" << std::endl;
			_lastName = "";
		}
	}
	formatName(_lastName);

	_nickname = "";
	while (_nickname == "")
	{
		if (!ut::askUser("nickname", _nickname))
			return false;
		if (ut::containsForbiddenChar(_nickname))
		{
			std::cout << "ERROR" << std::endl
				<< "forbidden characters" << std::endl;
			_nickname = "";
		}
	}

	_phoneNumber = "";
	while (_phoneNumber == "")
	{
		if (!ut::askUser("phone number", _phoneNumber))
			return false;
		_phoneNumber = ut::delWSpaces(_phoneNumber);
		if (ut::containsNonDigit(_phoneNumber))
		{
			std::cout << "ERROR" << std::endl
				<< "non-digit characters" << std::endl;
			_phoneNumber = "";
		}
	}

	_darkestSecret = "";
	while (_darkestSecret == "")
	{
		if (!ut::askUser("darkest secret", _darkestSecret))
			return false;
		if (ut::containsForbiddenChar(_darkestSecret))
		{
			std::cout << "ERROR" << std::endl
				<< "forbidden characters" << std::endl;
			_darkestSecret = "";
		}
	}

	return true;
}

void Contact::print10CharsWide(const std::string str) const
{
	if (str.length() > 10)
		std::cout << str.substr(0, 9) << ".";
	else
	{
		std::cout.width(10);
		std::cout << str;
	}
	std::cout << "|";
}

void Contact::printInline(int index) const
{
	std::cout.setf(std::ios_base::right);
	std::cout << "|";
	std::cout.width(10);
	std::cout << index << "|";
	print10CharsWide(_firstName);
	print10CharsWide(_lastName);
	print10CharsWide(_nickname);
	std::cout << std::endl;
}

void Contact::printFull(void) const
{
	std::cout << std::endl;
	std::cout << "First name: ";
	std::cout << _firstName << std::endl;
	std::cout << "Last name: ";
	std::cout << _lastName << std::endl;
	std::cout << "Nickname: ";
	std::cout << _nickname << std::endl;
	std::cout << "Phone number: ";
	std::cout << _phoneNumber << std::endl;
	std::cout << "Darkest secret: ";
	std::cout << _darkestSecret << std::endl;
	std::cout << std::endl;
}