#include "./Contact.hpp"

// Contact::Contact() {
// 	_firstName = "";
// 	_lastName = "";
// 	_nickName = "";
// 	_phoneNumber = "";
// 	_darkestSecret = "";
// }

void	Contact::set_first_name(const std::string str) { _firstName = str; }

void	Contact::set_last_name(const std::string str) { _lastName = str; }

void	Contact::set_nick_name(const std::string str) { _nickName = str; }

void	Contact::set_phone_number(const std::string str) { _phoneNumber = str; }

void	Contact::set_darkest_secret(const std::string str) { _darkestSecret = str; }

void	Contact::setting() {
	std::string	value = "";

	std::cout << "\033[34mPlease enter your first name : \033[0m";
	std::getline(std::cin, value);
	if (value == "")
		return ;
	set_first_name(value);
	std::cout << "\033[34mPlease enter your last name : \033[0m";
	std::getline(std::cin, value);
	if (value == "")
		return ;
	set_last_name(value);
	std::cout << "\033[34mPlease enter your nick name : \033[0m";
	std::getline(std::cin, value);
	if (value == "")
		return ;
	set_nick_name(value);
	std::cout << "\033[34mPlease enter your phone number : \033[0m";
	std::getline(std::cin, value);
	if (value == "")
		return ;
	set_nick_name(value);
	std::cout << "\033[34mPlease enter your darkest secret : \033[0m";
	std::getline(std::cin, value);
	if (value == "")
		return ;
	set_darkest_secret(value);
}
