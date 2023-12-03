#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_darkestSecret;

	void	print10CharsWide(const std::string str) const;
	void	formatName(std::string &name) const;

public:

	Contact(void);
	~Contact(void);
	bool 		setFromUserInput(void);
	void		printInline(const int index) const;
	void 		printFull(void) const;
};

#endif