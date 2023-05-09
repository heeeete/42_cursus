#include "PhoneBook.hpp"

int main() {
	std::string cmd;
	PhoneBook phone;

	while (1) {
		std::cout << "\033[33mPlease enter the command (ADD ㅣ SEARCH ㅣ EXIT)\033[0m" << std::endl << "==> ";
		std::getline(std::cin, cmd);
		if (std::cin.fail()){
			std::cout << "Bye Bye" << std::endl;
			exit(1);
		}
		else if (cmd == "ADD") {
			phone.add_contact();
		}
		else if (cmd == "SEARCH") {
			phone.search();
		}
		else if (cmd == "EXIT")	break;
	}
}
