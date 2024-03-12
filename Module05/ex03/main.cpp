#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	Intern intern;

	AForm * sc = intern.makeForm("Shrubbery Creation", "Forest");
	AForm * rr = intern.makeForm("ROBOTOMY REQUEST", "David");
	AForm * pp = intern.makeForm("presidential pardon", "Johnson");
	AForm * error = intern.makeForm("scform", "nobody");
	(void)error;

	Bureaucrat boss("The boss", 1);
	boss.signForm(*sc);
	boss.signForm(*rr);
	boss.signForm(*pp);
	boss.executeForm(*sc);
	boss.executeForm(*rr);
	boss.executeForm(*pp);
}