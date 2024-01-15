#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
private:

	std::string _ideas[100];

public:

	Brain(void);
	Brain(Brain const & src);
	~Brain(void);
	Brain & operator=(Brain const & rhs);

	void addIdea(std::string idea);

	std::string getIdea(int const & index) const;
};

#endif