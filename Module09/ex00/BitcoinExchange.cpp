#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

bool less::operator()(const std::string& x, const std::string& y) const
{
	std::string::const_iterator xIt = x.begin();
	std::string::const_iterator yIt = y.begin();

	while (xIt != x.end() && *xIt == *yIt)
	{
		xIt++;
		yIt++;
	}
	if (*xIt > *yIt)
		return true;
	return false;
}

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
	std::ifstream file(dbFileName.c_str());
	std::string line;

	if (!file.is_open())
		throw FileError();
	std::getline(file, line);
	while (!file.eof())
	{
		std::getline(file, line);
		if (line == "")
			continue;
		if (file.fail())
			throw FileError();
		try
		{
			checkDate(line, ',');
			checkValue(line, ',');
			_dict.insert(extractDateValue(line));
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << " => " << line << std::endl;
		}
	}
}

void BitcoinExchange::inputDbEstimate(std::string const & inputDbFileName)
{
	std::ifstream file(inputDbFileName.c_str());
	std::string line;
	std::pair<std::string, float> p;

	if (!file.is_open())
		throw FileError();
	std::getline(file, line);
	while (!file.eof())
	{
		std::getline(file, line);
		if (line == "")
			continue;
		if (file.fail())
			throw FileError();
		try
		{
			checkDate(line, '|');
			checkValue(line, '|');
			p = extractDateValue(line);
			if (_dict.lower_bound(p.first) == _dict.end())
				throw TooOldDateException();
			std::cout << p.first << " => " << p.second << " = "
				<< (*(_dict.lower_bound(p.first))).second * p.second
				<< std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << " => " << line << std::endl;
		}
	}
}

void BitcoinExchange::checkDate(std::string const & line, char sep) const
{
	std::string::const_iterator lIt = line.begin();
	std::string format = "NNNN-NN-NN";
	std::string::const_iterator fIt = format.begin();

	while (fIt < format.end())
	{
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
	mktime(&tm);
	if (year != tm.tm_year + 1900 || mon != tm.tm_mon + 1 || mday != tm.tm_mday)
		throw InexistantDateException();
}

void BitcoinExchange::checkValue(std::string const & line, char sep) const
{
	std::string::const_iterator lIt = line.begin();
	std::string::const_iterator vIt;
	int nDigits = 0;
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
	vIt = lIt;
	while (lIt != line.end())
	{
		if (!std::isdigit(*lIt) && (dotEncountered || *lIt != '.'))
			throw BadValueException();
		if (*lIt == '.')
			dotEncountered = true;
		if (!dotEncountered)
			nDigits++;
		lIt++;
	}
	if (nDigits > 10 || atof(&*vIt) > 2147483647)
		throw TooBigValueException();
}

std::pair<std::string, float> BitcoinExchange::extractDateValue(std::string const & line)
{
	std::string date = line.substr(0, 10);
	float value;
	int valueI = 10;

	while (isspace(line[valueI]))
		valueI++;
	valueI++;
	while (isspace(line[valueI]))
		valueI++;
	value = atof(line.substr(valueI).c_str());
	return std::make_pair(date, value);
}

std::map<std::string, float, less> const & BitcoinExchange::getDict(void) const
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

const char * BitcoinExchange::TooOldDateException::what(void) const throw()
{
	return "Error: Date is too old for database";
}

const char * BitcoinExchange::NoValueException::what(void) const throw()
{
	return "Error: No value indicated";
}

const char * BitcoinExchange::BadValueException::what(void) const throw()
{
	return "Error: Value should be a positive floating number";
}

const char * BitcoinExchange::TooBigValueException::what(void) const throw()
{
	return "Error: Value is too big";
}

const char * BitcoinExchange::FileError::what(void) const throw()
{
	return "Error: File failed to be read";
}