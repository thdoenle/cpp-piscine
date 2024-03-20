#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	Intern intern;
	AForm * sc;
	AForm * rr;
	AForm * pp;
	AForm * error;

	try
	{
		sc = intern.makeForm("Shrubbery Creation", "Forest");
		rr = intern.makeForm("ROBOTOMY REQUEST", "David");
		pp = intern.makeForm("presidential pardon", "Johnson");
		error = intern.makeForm("scform", "nobody");
		(void)error;
	}
	catch (std::exception const & e)
	{
		std::cout << e.what() << std::endl;
		exit(errno);
	}

	Bureaucrat boss("The boss", 1);
	boss.signForm(*sc);
	boss.signForm(*rr);
	boss.signForm(*pp);
	boss.executeForm(*sc);
	boss.executeForm(*rr);
	boss.executeForm(*pp);

	delete sc;
	delete rr;
	delete pp;
	delete error;
}