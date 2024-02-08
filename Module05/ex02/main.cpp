#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Form form("Error", 0, 50);
		std::cout << form;
	}
	catch (const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Form form("Error", 30, 180);
		std::cout << form;
	}
	catch (const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	try
	{
		Bureaucrat lowB("Not the boss", 150);
		std::cout << lowB;
		Form middle("Middle", 75, 75);
		middle.beSigned(lowB);
		std::cout << "middle" << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	Form conf("Confidential", 5, 5);
	Bureaucrat boris("Boris", 6);

	boris.signForm(conf);
	boris.incGrade();
	boris.signForm(conf);
	boris.signForm(conf);
}