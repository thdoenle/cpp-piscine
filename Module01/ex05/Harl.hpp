#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl
{
private:

	static void 		(Harl::*_f[4])(void) const;
	static std::string	_levels[4];

	void debug(void) const;
	void info(void) const;
	void warning(void) const;
	void error(void) const;

public:

	Harl(void);
	~Harl(void);
	void complain(std::string level) const;
};

typedef void (Harl::*HarlMemberFn)(void) const;

#endif