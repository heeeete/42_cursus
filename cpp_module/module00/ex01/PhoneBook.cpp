#include "PhoneBook.hpp"
#include <iomanip>

#define C_RED "\033[31m"

int PhoneBook::idx = 0;

PhoneBook::~PhoneBook() {}

std::string	PhoneBook::read_line() const {
	std::string	str;

	std::getline(std::cin, str);
	if (std::cin.fail()){
		exit (1);
	}
	else if (str.find_first_not_of("0123456789") != std::string::npos) {
		throw std::exception();
	}
	return str;
}

void	PhoneBook::add_contact() {
	if (!(_contacts[idx].setting())) {
		std::cout << C_RED << "Empty values are not allowed." << std::endl;
	} else {
		if (++idx >= 8) idx = 0;
	}
}

void	PhoneBook::search() const {
	std::cout << '|' << std::setw(11);
	std::cout << '|' << std::setw(10) << "first_name";
	std::cout << '|' << std::setw(10) << "last_name";
	std::cout << '|' << std::setw(10) << "nick_name";
	std::cout << '|' << std::setw(10) << "p_number";
	std::cout << '|' << std::endl;
	for (int i = 0; i < 8; i++) {
		std::cout << '|' << std::setw(10) << i;
		std::cout << '|' << std::setw(10) << _contacts[i].get_first_name();
		std::cout << '|' << std::setw(10) << _contacts[i].get_last_name();
		std::cout << '|' << std::setw(10) << _contacts[i].get_nick_name();
		std::cout << '|' << std::setw(10) << _contacts[i].get_phone_number();
		std::cout << '|' << std::endl;
	}
	std::cout << "Please enter the index : ";
	std::string	str;
	int	idx;
	try
	{
		str = read_line();
		if (str.length() != 1)
			throw std::exception();
		idx = str[0] - '0';
		if (0 <= idx && idx <= 7) {
			std::cout << "first_name :" << _contacts[idx].get_first_name() << std::endl;
    		std::cout << "last_name :" << _contacts[idx].get_last_name() << std::endl;
			std::cout << "nick_name :" << _contacts[idx].get_nick_name() << std::endl;
			std::cout << "phone_number :" << _contacts[idx].get_phone_number() << std::endl;
		}
		else	std::exception();

	}
	catch(const std::exception& e)
	{
		std::cout << "Invalid index" << std::endl;
	}

}
