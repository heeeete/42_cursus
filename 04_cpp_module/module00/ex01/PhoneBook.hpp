#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	Contact	_contacts[8];
	int		idx;
	int		size;

	public:
		PhoneBook () : idx(0), size(0) {};
		void	add_contact();
		void	search() const;
		void	idx_search() const;
		bool	set_contact();

		std::string	convert_str(std::string str) const ;
		std::string	read_line() const;
		~PhoneBook ();
};

#endif
