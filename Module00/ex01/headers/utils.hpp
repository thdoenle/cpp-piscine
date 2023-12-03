#ifndef UTILS_HPP
# define UTILS_HPP

# include <string>

namespace ut
{
	bool		containsNonAlpha(const std::string str);
	bool		containsNonDigit(const std::string str);
	bool		containsForbiddenChar(const std::string str);
	std::string trimWSpaces(const std::string str);
	std::string delWSpaces(const std::string str);
	void		printIn(void);
	void		printOut(void);
	bool		askUser(const std::string what, std::string &dest);
}

#endif