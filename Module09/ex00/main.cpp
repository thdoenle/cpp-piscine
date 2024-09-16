#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2)
		return 1;
	(void)av;

	BitcoinExchange bExchange;
	bExchange.dbInit("data.csv");
}