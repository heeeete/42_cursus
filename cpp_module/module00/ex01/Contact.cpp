#include "./Contact.hpp"

Contact::~Contact() {}

void	Contact::set_first_name(const std::string str) { _first_name = str; }

void	Contact::set_last_name(const std::string str) { _last_name = str; }

void	Contact::set_nick_name(const std::string str) { _nick_name = str; }

void	Contact::set_phone_number(const std::string str) { _phone_number = str; }

void	Contact::set_darkest_secret(const std::string str) { _darkest_secret = str; }

// bool		Contact::set_contact() {
// 	std::string	first_name = "";
// 	std::string	last_name = "";
// 	std::string	nick_name = "";
// 	std::string	phone_number = "";
// 	std::string	darkest_secret = "";

// 	std::cout << "\033[34mPlease enter your first name : \033[0m";
// 	std::getline(std::cin, first_name);
// 	if (first_name == "")
// 		return false;
// 	std::cout << "\033[34mPlease enter your last name : \033[0m";
// 	std::getline(std::cin, last_name);
// 	if (last_name == "")
// 		return false;
// 	std::cout << "\033[34mPlease enter your nick name : \033[0m";
// 	std::getline(std::cin, nick_name);
// 	if (nick_name == "")
// 		return false;
// 	std::cout << "\033[34mPlease enter your phone number : \033[0m";
// 	std::getline(std::cin, phone_number);
// 	if (phone_number == "")
// 		return false;
// 	std::cout << "\033[34mPlease enter your darkest secret : \033[0m";
// 	std::getline(std::cin, darkest_secret);
// 	if (darkest_secret == "")
// 		return false;
// 	set_first_name(first_name);
// 	set_last_name(last_name);
// 	set_nick_name(nick_name);
// 	set_phone_number(phone_number);
// 	set_darkest_secret(darkest_secret);
// 	return true;
// }

std::string	Contact::get_first_name() const  { return _first_name; }

std::string	Contact::get_last_name() const  { return _last_name; }

std::string	Contact::get_nick_name() const  { return _nick_name; }

std::string	Contact::get_phone_number() const  { return _phone_number; }

std::string	Contact::get_darkest_secret() const  { return _darkest_secret; }
