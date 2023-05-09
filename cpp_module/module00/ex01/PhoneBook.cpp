#include "PhoneBook.hpp"
#include <iomanip>

#define C_RED "\033[31m"

PhoneBook::~PhoneBook() {}

std::string	PhoneBook::read_line() const {
	std::string	str;

	std::getline(std::cin, str);
	if (std::cin.fail()){
		std::cout << std::endl << "Bye Bye" << std::endl;
		exit (1);
	}
	else if (str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_- ") != std::string::npos) {
		throw std::exception();
	}
	return str;
}

bool		PhoneBook::set_contact() {
	std::string	first_name = "";
	std::string	last_name = "";
	std::string	nick_name = "";
	std::string	phone_number = "";
	std::string	darkest_secret = "";

	try
	{
		std::cout << "\033[34mPlease enter your first name : \033[0m";
		first_name = read_line();
		if (first_name == "")
			return false;
		std::cout << "\033[34mPlease enter your last name : \033[0m";
		last_name = read_line();
		if (last_name == "")
			return false;
		std::cout << "\033[34mPlease enter your nick name : \033[0m";
		nick_name = read_line();
		if (nick_name == "")
			return false;
		std::cout << "\033[34mPlease enter your phone number : \033[0m";
		phone_number = read_line();
		if (phone_number == "")
			return false;
		std::cout << "\033[34mPlease enter your darkest secret : \033[0m";
		darkest_secret = read_line();
		if (darkest_secret == "")
			return false;
		_contacts[idx].set_first_name(first_name);
		_contacts[idx].set_last_name(last_name);
		_contacts[idx].set_nick_name(nick_name);
		_contacts[idx].set_phone_number(phone_number);
		_contacts[idx].set_darkest_secret(darkest_secret);
		if (size < 8) size++;
	}
	catch(const std::exception& e)
	{
		return false;
	}
	return true;
}

void	PhoneBook::add_contact() {
	std::cout << "Special characters can only be" << C_RED << "'_''-'" << "\033[0m" << std::endl;
	if (!(set_contact())) {
		std::cout << C_RED << "Invalid value" << std::endl;
	} else {
		if (++idx >= 8) idx = 0;
	}
}

void	PhoneBook::idx_search() const {
	std::cout << "Please enter the index : ";
	std::string	str;
	int	idx;
	try
	{
		str = read_line();
		idx = str[0] - '0';
		if (str.length() != 1 || !(0 <= idx && idx <= 7))
			throw std::exception();
		if (_contacts[idx].get_first_name() != "") {
			std::cout << "first_name :" << _contacts[idx].get_first_name() << std::endl;
    		std::cout << "last_name :" << _contacts[idx].get_last_name() << std::endl;
			std::cout << "nick_name :" << _contacts[idx].get_nick_name() << std::endl;
			std::cout << "phone_number :" << _contacts[idx].get_phone_number() << std::endl;
		}
		else if (_contacts[idx].get_first_name() == "") std::cout << "\033[33mempty contact" << std::endl;
		else	throw std::exception();

	}
	catch(const std::exception& e)
	{
		std::cout << C_RED << "Invalid index" << std::endl;
	}
}

std::string	PhoneBook::convert_str(std::string str) const {
	std::string	temp = str;
	if (temp.length() >= 10) {
		temp.resize(10);
		temp[9] = '.';
	}
	return temp;
}

void	PhoneBook::search() const {
	std::cout << '|' << std::setw(10) << "index";
	std::cout << '|' << std::setw(10) << "first_name";
	std::cout << '|' << std::setw(10) << "last_name";
	std::cout << '|' << std::setw(10) << "nick_name";
	std::cout << '|' << std::endl;
	for (int i = 0; i < size; i++) {
		std::cout << '|' << std::setw(10) << i;
		std::cout << '|' << std::setw(10) << convert_str(_contacts[i].get_first_name());
		std::cout << '|' << std::setw(10) << convert_str(_contacts[i].get_last_name());
		std::cout << '|' << std::setw(10) << convert_str(_contacts[i].get_nick_name());
		std::cout << '|' << std::endl;
	}
	idx_search();
}
