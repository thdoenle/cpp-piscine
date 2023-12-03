#include "utils.hpp"
#include <iostream>

bool ut::containsNonAlpha(const std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
		if (!isalpha(str[i]))
			return true;
	return false;
}

bool ut::containsNonDigit(const std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
		if (!isdigit(str[i]))
			return true;
	return false;
}

bool ut::containsForbiddenChar(const std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
		if (str[i] < ' ' && !isspace(str[i]))
			return true;
	return false;
}

std::string ut::trimWSpaces(const std::string str)
{
	std::size_t	start = 0;
	std::size_t	end;

	while (start < str.length() && isspace(str[start]))
		start++;
	if (start == str.length())
		return "";
	end = str.length();
	while (end > 0 && isspace(str[end - 1]))
		end--;
	return str.substr(start, end - start);
}

std::string ut::delWSpaces(const std::string str)
{
	std::string res;
	size_t		j;

	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isspace(str[i]))
		{
			j = i;
			while (j < str.length() && !isspace(str[j]))
				j++;
			res += str.substr(i, j - i);
			i = j;
		}
	}
	return res;
}

void ut::printIn(void)
{
	std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
}

void ut::printOut(void)
{
	std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;
}

bool ut::askUser(const std::string what, std::string &dest)
{
	std::cout << "Enter " << what << ": ";
	if (!std::getline(std::cin, dest) || std::cin.eof())
	{
		std::cout << std::endl << "FATAL ERROR" << std::endl;
		return false;
	}
	dest = ut::trimWSpaces(dest);
	return true;
}