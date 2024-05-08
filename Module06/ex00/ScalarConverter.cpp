#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

int ScalarConverter::detectType(std::string const & literal)
{
	if (literal.size() == 1 && !isdigit(literal[0]))
		return CHAR;
	if (literal == "nanf" || literal == "-inff" || literal == "+inff")
		return FLOAT;
	if (literal == "nan" || literal == "-inf" || literal == "+inf")
		return DOUBLE;

	int ret = INT;
	for (size_t i = (literal[0] == '-' ? 1 : 0); i < literal.size(); i++)
	{
		if (isdigit(literal[i]))
			continue;
		else if (literal[i] == '.')
			if (ret == DOUBLE)
				return ERROR;
			else
				ret = DOUBLE;
		else if (literal[i] == 'f' && i + 1 == literal.size())
			ret = FLOAT;
		else 
			return ERROR;
	}
	return ret;
}

void ScalarConverter::convert(std::string const & literal)
{
	int type = detectType(literal);
	
	if (type == CHAR)
		std::cout << "char: ";
	else if (type == INT)
		std::cout << "int: ";
	else if (type == FLOAT)
		std::cout << "float: ";
	else if (type == DOUBLE)
		std::cout << "double: ";
	std::cout << std::endl;
}
