#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat john("John", 72);
	Bureaucrat boss("The Boss", 1);

	std::cout << std::endl;
	ShrubberyCreationForm garden("garden");
	john.executeForm(garden);
	john.signForm(garden);
	john.executeForm(garden);

	std::cout << std::endl;
	RobotomyRequestForm subject("Subject 427");
	john.signForm(subject);
	boss.executeForm(subject);
	boss.signForm(subject);
	john.executeForm(subject);

	std::cout << std::endl;
	PresidentialPardonForm stanley("Stanley");
	boss.executeForm(stanley);
	boss.signForm(stanley);
	john.executeForm(stanley);
	boss.executeForm(stanley);

	std::cout << std::endl;
}