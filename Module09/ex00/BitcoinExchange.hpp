#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <map>
#include <string>
#include <exception>
#include <ctime>

class BitcoinExchange
{
private:

	std::map<std::string, float> _dict;

	void checkDate(std::string const & line, char sep) const;
	void checkValue(std::string const & line, char sep) const;

public:

	BitcoinExchange(void);
	BitcoinExchange(BitcoinExchange const & src);
	~BitcoinExchange(void);
	BitcoinExchange & operator=(BitcoinExchange const & rhs);

	void dbInit(std::string const & dbFileName);

	std::map<std::string, float> const & getDict(void) const;

	class InexistantDateException : public std::exception
	{
	public:
		virtual const char * what(void) const throw();
	};

	class BadDateFormatException : public std::exception
	{
	public:
		virtual const char * what(void) const throw();
	};

	class NoValueException : public std::exception
	{
	public:
		virtual const char * what(void) const throw();
	};

	class BadValueException : public std::exception
	{
	public:
		virtual const char * what(void) const throw();
	};
};

#endif