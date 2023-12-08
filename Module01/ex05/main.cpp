#include "Harl.hpp"
#include <iostream>

int main(void)
{
	Harl harl;
	std::cout << std::endl;

	harl.complain("ERROR");
	harl.complain("WARNING");
	harl.complain("INFO");
	harl.complain("DEBUG");
	harl.complain("nothing");
}