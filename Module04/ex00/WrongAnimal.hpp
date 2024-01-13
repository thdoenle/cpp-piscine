#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <string>

class WrongAnimal
{
protected:

	std::string _type;

public:

	WrongAnimal(void);
	WrongAnimal(WrongAnimal const & src);
	virtual ~WrongAnimal(void);
	WrongAnimal & operator=(WrongAnimal const & rhs);

	void makeSound(void) const;
	std::string getType(void) const;
};

#endif