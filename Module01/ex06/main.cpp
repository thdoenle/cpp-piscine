#include "Harl.hpp"
#include <iostream>

int main(int ac, char *av[])
{
	if (ac != 2)
	{
		std::cout << "Usage: ./harlFilter LEVEL" << std::endl;
		return 0;
	}

	Harl harl;
	harl.complain(av[1]);
}