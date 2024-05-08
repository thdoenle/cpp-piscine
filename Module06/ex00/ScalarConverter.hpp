#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>

class ScalarConverter
{
private:

	enum
	{
		ERROR,
		CHAR,
		INT,
		FLOAT,
		DOUBLE
	};

	static int detectType(std::string const & literal);

public:

	static void convert(std::string const & literal);
};

#endif