#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:

	Brain * _brain;

public:

	Cat(void);
	Cat(Cat const & src);
	~Cat(void);
	Cat & operator=(Cat const & rhs);

	void makeSound(void) const;
	void addIdea(std::string idea);
	void tellIdeas(void) const;

	Brain const & getBrain(void) const;
};

#endif