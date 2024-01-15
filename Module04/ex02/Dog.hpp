#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
private:

	Brain * _brain;

public:

	Dog(void);
	Dog(Dog const & src);
	~Dog(void);
	Dog & operator=(Dog const & rhs);

	void makeSound(void) const;
	void addIdea(std::string idea);
	void tellIdeas(void) const;

	Brain const & getBrain(void) const;
};

#endif