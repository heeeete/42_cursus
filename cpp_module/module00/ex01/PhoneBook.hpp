#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	Contact	_contacts[8];
	static int	idx;

	public:
		void	add_contact();
		void	search() const;
		std::string	read_line() const;
		~PhoneBook ();
};

#endif
