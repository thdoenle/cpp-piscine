#ifndef WRONG_DOG_HPP
#define WRONG_DOG_HPP

#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal
{
public:

	WrongDog(void);
	WrongDog(WrongDog const & src);
	~WrongDog(void);
	WrongDog & operator=(WrongDog const & rhs);

	void makeSound(void) const;
};

#endif