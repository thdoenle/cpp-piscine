#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

Dog::Dog(void)
{
	_type = "Dog";
	_brain = new Brain;
	std::cout << "Dog default created" << std::endl;
}

Dog::Dog(Dog const & src) : Animal(src)
{
	_brain = new Brain(src.getBrain());
	std::cout << "Dog copy created" << std::endl;
}

Dog::~Dog(void)
{
	delete _brain;
	std::cout << "Dog destroyed" << std::endl;
}

Dog & Dog::operator=(Dog const & rhs)
{
	_type = rhs.getType();
	*_brain = rhs.getBrain();
	return *this;
}

void Dog::addIdea(std::string idea)
{
	_brain->addIdea(idea);
}

void Dog::tellIdeas(void) const
{
	int i = 0;

	std::cout << "(";
	while (i < 100 && _brain->getIdea(i) != "")
	{
		if (i > 0)
			std::cout << "; ";
		std::cout << _brain->getIdea(i);
		i++;
	}
	std::cout << ")" << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "Woof!" << std::endl;
}

Brain const & Dog::getBrain(void) const
{
	return *_brain;
}