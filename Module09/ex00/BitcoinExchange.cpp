#include "BitcoinExchange.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src)
	: _dict(src.getDict()) {}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & rhs)
{
	_dict = rhs.getDict();
	return *this;
}

void BitcoinExchange::dbInit(std::string const & dbFileName)
{
	(void)dbFileName;
	std::string line = "2024-34-01";
	try
	{
		checkDate(line, ',');
		std::cout << line << " is OK" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << " => " << line << std::endl;
	}
	line = "2024-12-22   ,   1";
	try
	{
		checkDate(line, ',');
		checkValue(line, ',');
		std::cout << line << " is OK" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << " => " << line << std::endl;
	}
}

void BitcoinExchange::checkDate(std::string const & line, char sep) const
{
	std::string::const_iterator lIt = line.begin();
	std::string format = "NNNN-NN-NN";
	std::string::const_iterator fIt = format.begin();

	while (fIt < format.end())
	{
		std::cout << "'" << *lIt << "'" << std::endl;
		if (lIt == line.end()
			|| (*fIt == 'N' && !std::isdigit(*lIt))
			|| (*fIt == '-' && *lIt != '-'))
			throw BadDateFormatException();
		lIt++;
		fIt++;
	}
	while (std::isspace(*lIt))
		lIt++;
	if (*lIt != sep)
		throw BadDateFormatException();

	lIt = line.begin();
	while (std::isspace(*lIt))
		lIt++;
	std::tm tm;
	int year = atoi(&*lIt);
	int mon = atoi(&*lIt + 5);
	int mday = atoi(&*lIt + 8);
	tm.tm_year = year - 1900;
	tm.tm_mon = mon - 1;
	tm.tm_mday = mday;
	tm.tm_hour = 12;
    tm.tm_min = 0;
    tm.tm_sec = 0;
    tm.tm_isdst = 0;
	std::cout << tm.tm_year + 1900 << " " << tm.tm_mon + 1 << " " << tm.tm_mday << std::endl;
	mktime(&tm);
	std::cout << tm.tm_year + 1900 << " " << tm.tm_mon + 1 << " " << tm.tm_mday << std::endl;
	if (year != tm.tm_year + 1900 || mon != tm.tm_mon + 1 || mday != tm.tm_mday)
		throw InexistantDateException();
}

void BitcoinExchange::checkValue(std::string const & line, char sep) const
{
	std::string::const_iterator lIt = line.begin();
	bool dotEncountered = false;

	while (lIt != line.end() && *lIt != sep)
		lIt++;
	if (lIt == line.end())
		throw NoValueException();
	lIt++;
	while (std::isspace(*lIt))
		lIt++;
	if (lIt == line.end())
		throw NoValueException();
	while (lIt != line.end())
	{
		if (!std::isdigit(*lIt) && (dotEncountered || *lIt != '.'))
			throw BadValueException();
		if (*lIt == '.')
			dotEncountered = true;
		lIt++;
	}
}

std::map<std::string, float> const & BitcoinExchange::getDict(void) const
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

const char * BitcoinExchange::NoValueException::what(void) const throw()
{
	return "Error: No value indicated";
}

const char * BitcoinExchange::BadValueException::what(void) const throw()
{
	return "Error: Value should be a positive floating number";
}