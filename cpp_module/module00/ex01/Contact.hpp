#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact {
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickName;
	std::string	_phoneNumber;
	std::string	_darkestSecret;

	public:
		Contact() : _firstName(""), _lastName(""), _nickName(""), _phoneNumber(""), _darkestSecret("") {}


		void	set_first_name(const std::string str);
		void	set_last_name(const std::string str);
		void	set_nick_name(const std::string str);
		void	set_phone_number(const std::string str);
		void	set_darkest_secret(const std::string str);
		void	setting();
};

#endif
