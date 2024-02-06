#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat joe(0, "Joe");
		std::cout << joe;
	}
	catch (const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Bureaucrat joe(160, "Joe");
		std::cout << joe;
	}
	catch (const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	try
	{
		Bureaucrat highB(1, "The boss");
		std::cout << highB;
		highB.incGrade();
	}
	catch (const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Bureaucrat lowB(150, "Not the boss");
		std::cout << lowB;
		lowB.incGrade();
		lowB.decGrade();
		lowB.decGrade();
	}
	catch (const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}