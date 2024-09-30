#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2)
		return 1;

	BitcoinExchange bExchange;
	try
	{
		bExchange.dbInit("data.csv");
	}
	catch (std::exception const & e)
	{
		std::cerr << e.what() << std::endl;
		std::cerr << "Could not initialize database" << std::endl;
		return 1;
	}
	try
	{
		bExchange.inputDbEstimate(av[1]);
	}
	catch (std::exception const & e)
	{
		std::cerr << e.what() << std::endl;
		std::cerr << "Could not read input file" << std::endl;
		return 1;
	}
}