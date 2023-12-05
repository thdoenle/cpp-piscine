#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
	static int _nbInst;

	std::string _name;
	int			_index;

public:

	Zombie(std::string const name);
	Zombie(void);
	~Zombie(void);
	void setName(std::string const name);
	void announce(void) const;
};

Zombie* zombieHorde(int const n, std::string const name);

#endif