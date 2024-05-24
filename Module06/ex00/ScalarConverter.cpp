#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <limits>

#include <bitset>

int ScalarConverter::detectType(std::string const & literal)
{
	if (literal.size() == 1 && !isdigit(literal[0]))
		return CHAR;
	if (literal == "nanf" || literal == "-inff" || literal == "inff")
		return FLOAT;
	if (literal == "nan" || literal == "-inf" || literal == "inf")
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

void ScalarConverter::convertFromChar(std::string const & literal)
{
	char c = literal[0];

	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::convertFromInt(std::string const & literal)
{
	long res = static_cast<long>(atol(literal.c_str()));

	if (std::numeric_limits<int>::max() < res || std::numeric_limits<int>::min() > res)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
	else
	{
		if (res >= 32 && res < 127)
			std::cout << "char: '" << static_cast<char>(res) << "'" << std::endl;
		else if (res >= std::numeric_limits<char>::min()
			&& res <= std::numeric_limits<char>::max())
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: impossible" << std::endl;
		std::cout << "int: " << literal << std::endl;
		std::cout << "float: " << static_cast<float>(res) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(res) << ".0" << std::endl;
	}
}

void ScalarConverter::convertFromFloat(std::string const & literal)
{
	float f = static_cast<float>(atof(literal.c_str()));

	if (f >= 32.0f && f < 127.0f)
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	else if (f >= std::numeric_limits<char>::min()
		&& f < std::numeric_limits<char>::max() + 1)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	if (static_cast<long long>(f) != static_cast<int>(f)
		|| isnanf(f))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	if (static_cast<float>(static_cast<long long>(f)) == f)
	{
		std::cout << "float: " << f << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(f) << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(f) << std::endl;
	}
}

void ScalarConverter::convertFromDouble(std::string const & literal)
{
	double d = static_cast<double>(atof(literal.c_str()));

	if (d >= 32.0 && d < 127.0)
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	else if (d >= std::numeric_limits<char>::min()
		&& d < std::numeric_limits<char>::max() + 1)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	if (static_cast<long long>(d) != static_cast<int>(d)
		|| std::isnan(d))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	if (static_cast<double>(static_cast<long long>(d)) == d)
	{
		std::cout << "float: " << static_cast<float>(d) << ".0f" << std::endl;
		std::cout << "double: " << d << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
}

void ScalarConverter::convert(std::string const & literal)
{
	std::cout.precision(100);
	switch (detectType(literal))
	{
	case CHAR:
		convertFromChar(literal);
		break;
	case INT:
		convertFromInt(literal);
		break;
	case FLOAT:
		convertFromFloat(literal);
		break;
	case DOUBLE:
		convertFromDouble(literal);
		break;
	default:
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}
