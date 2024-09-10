#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <map>
#include <string>
#include <exception>

class BitcoinExchange
{
private:

	std::map<std::string, float> _dict;

	void checkDate(std::string const & line) const;

public:

	BitcoinExchange(void);
	BitcoinExchange(BitcoinExchange const & src);
	~BitcoinExchange(void);
	BitcoinExchange & operator=(BitcoinExchange const & rhs);

	std::map<std::string, float> const & get_dict(void) const;

	class InexistantDateException : std::exception
	{
	public:
		virtual const char * what(void) const throw();
	};

	class BadDateFormatException : std::exception
	{
	public:
		virtual const char * what(void) const throw();
	};
};

#endif