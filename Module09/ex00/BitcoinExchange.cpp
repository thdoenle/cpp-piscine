#include "BitcoinExchange.hpp"
#include <iostream>
#include <ctime>

BitcoinExchange::BitcoinExchange(void)
{
	std::tm tm;
	tm.tm_year = 2024 - 1900;
	tm.tm_mon = 1 - 1;
	tm.tm_mday = 1;
	tm.tm_hour = 12;
    tm.tm_min = 0;
    tm.tm_sec = 0;
    tm.tm_isdst = 0;
	std::time_t t = mktime(&tm);
	std::cout << tm.tm_year + 1900 << "-" << tm.tm_mon + 1 << "-" << tm.tm_mday << std::endl;

	std::cout << t << std::endl;
	std::cout << std::asctime(std::gmtime(&t));

	std::string line = "  2024-34-01";
	try
	{
		checkDate(line);
		std::cout << line << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << " => " << line << std::endl;
	}
	line = " 2O24-24-22";
	try
	{
		checkDate(line);
		std::cout << line << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << " => " << line << std::endl;
	}
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src)
	: _dict(src.get_dict()) {}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & rhs)
{
	_dict = rhs.get_dict();
	return *this;
}

void BitcoinExchange::checkDate(std::string const & line) const
{
	std::string::const_iterator lIt = line.begin();
	std::string format = "NNNN-NN-NN";
	std::string::const_iterator fIt = format.begin();

	while (fIt < format.end())
	{
		while (std::isspace(*lIt))
			lIt++;
		if (lIt == line.end()
			|| (*fIt == 'N' && !std::isdigit(*lIt))
			|| (*fIt == '-' && *lIt != '-'))
			throw BadDateFormatException();
		lIt++;
		fIt++;
	}
}

std::map<std::string, float> const & BitcoinExchange::get_dict(void) const
{
	return _dict;
}

const char * BitcoinExchange::InexistantDateException::what(void) const throw()
{
	return "Error: Date doesn't exist";
}

const char * BitcoinExchange::BadDateFormatException::what(void) const throw()
{
	return "Error: Date format is bad";
}