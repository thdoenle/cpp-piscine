#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
protected:

	std::string _type;

public:

	Animal(void);
	Animal(Animal const & src);
	virtual ~Animal(void);
	Animal & operator=(Animal const & rhs);

	virtual void makeSound(void) const;
	std::string getType(void) const;
};

#endif