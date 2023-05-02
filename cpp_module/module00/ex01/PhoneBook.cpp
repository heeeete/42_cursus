#include "./Contact.hpp"

int main() {
	std::string cmd;
	Contact a;

	while (1) {
		std::cout << "\033[33mPlease enter the command (ADD ㅣ SEARCH ㅣ EXIT)\033[0m" << std::endl << "==> ";
		std::getline(std::cin, cmd);
		if (cmd == "ADD") {
			a.setting();
		}

		// else if (cmd == "SEARCH")
		// else if (cmd == "EXIT")
	}
}
