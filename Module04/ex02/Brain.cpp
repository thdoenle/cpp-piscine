#include "Brain.hpp"
#include <iostream>

Brain::Brain(void)
{
	std::cout << "Brain default created" << std::endl;
}

Brain::Brain(Brain const & src)
{
	*this = src;
	std::cout << "Brain copy created" << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "Brain destroyed" << std::endl;
}

Brain & Brain::operator=(Brain const & rhs)
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = rhs.getIdea(i);
	return *this;
}

void Brain::addIdea(std::string idea)
{
	int i = 0;

	while (i < 100 && _ideas[i] != "")
		i++;
	if (i == 100)
		return;
	_ideas[i] = idea;
}

std::string Brain::getIdea(int const & index) const
{
	if (index < 0 || index >= 100)
		return "";
	return _ideas[index];
}