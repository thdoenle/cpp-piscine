#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <map>
#include <string>
#include <exception>
#include <ctime>

struct less : std::binary_function<std::string, std::string, bool>
{
	bool operator() (const std::string& x, const std::string& y) const;
};

class BitcoinExchange
{
private:

	std::map<std::string, float, less> _dict;

	void checkDate(std::string const & line, char sep) const;
	void checkValue(std::string const & line, char sep) const;
	std::pair<std::string, float> extractDateValue(std::string const & line);

public:

	BitcoinExchange(void);
	BitcoinExchange(BitcoinExchange const & src);
	~BitcoinExchange(void);
	BitcoinExchange & operator=(BitcoinExchange const & rhs);

	void dbInit(std::string const & dbFileName);
	void inputDbEstimate(std::string const & inputDbFileName);

	std::map<std::string, float, less> const & getDict(void) const;

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

	class TooOldDateException : public std::exception
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

	class TooBigValueException : public std::exception
	{
	public:
		virtual const char * what(void) const throw();
	};

	class FileError : public std::exception
	{
	public:
		virtual const char * what(void) const throw();
	};
};

#endif