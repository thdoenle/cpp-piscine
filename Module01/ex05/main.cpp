#include "Harl.hpp"
#include <iostream>

int main(void)
{
	Harl harl;

	harl.complain("ERROR");
	harl.complain("WARNING");
	harl.complain("INFO");
	harl.complain("DEBUG");
	harl.complain("nothing");
}