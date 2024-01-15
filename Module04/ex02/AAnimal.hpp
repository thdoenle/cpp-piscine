#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>

class AAnimal
{
protected:

	std::string _type;

public:

	AAnimal(void);
	AAnimal(AAnimal const & src);
	virtual ~AAnimal(void);
	AAnimal & operator=(AAnimal const & rhs);

	virtual void makeSound(void) const = 0;
	std::string getType(void) const;
};

#endif