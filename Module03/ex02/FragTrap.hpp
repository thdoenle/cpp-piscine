#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class FragTrap : public ClapTrap
{
public:

	FragTrap(void);
	FragTrap(std::string const & name);
	FragTrap(FragTrap const & src);
	~FragTrap(void);
	FragTrap & operator=(FragTrap const & rhs);

	void highFivesGuys(void);
};

#endif