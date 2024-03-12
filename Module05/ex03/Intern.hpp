#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>

class Intern;

typedef AForm * (Intern::*InternNewFormFn)(std::string const & target) const;

class Intern
{
private:

	static InternNewFormFn _newFormFns[3];
	static std::string _formNames[3];

	AForm * newSCForm(std::string const & target) const;
	AForm * newRRForm(std::string const & target) const;
	AForm * newPPForm(std::string const & target) const;

public:

	Intern(void);
	Intern(Intern const & src);
	~Intern(void);
	Intern & operator=(Intern const & rhs);

	AForm * makeForm(std::string name, std::string const & target) const;
};

#endif