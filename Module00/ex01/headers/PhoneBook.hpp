#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	static const int MAX_NUM_CONTACT = 8;

	Contact _contacts[MAX_NUM_CONTACT];
	int		_curContact;
	int		_numContact;

	void 	printContacts(void) const;
	int		askIndex(void) const;

public:

	PhoneBook(void);
	~PhoneBook(void);
	bool addNewContact(void);
	bool searchContact(void) const;
};

#endif