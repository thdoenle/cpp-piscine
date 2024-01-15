#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

Cat::Cat(void)
{
	_type = "Cat";
	_brain = new Brain();
	std::cout << "Cat default created" << std::endl;
}

Cat::Cat(Cat const & src) : AAnimal(src)
{
	_brain = new Brain(src.getBrain());
	std::cout << "Cat copy created" << std::endl;
}

Cat::~Cat(void)
{
	delete _brain;
	std::cout << "Cat destroyed" << std::endl;
}

Cat & Cat::operator=(Cat const & rhs)
{
	_type = rhs.getType();
	*_brain = rhs.getBrain();
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "Meeoooow..." << std::endl;
}

void Cat::addIdea(std::string idea)
{
	_brain->addIdea(idea);
}

void Cat::tellIdeas(void) const
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

Brain const & Cat::getBrain(void) const
{
	return *_brain;
}