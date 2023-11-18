#include <iostream>
#include "BitcoinExchange.hpp"

int main(int ac, char **av){
	if (ac == 2){
		try
		{
			BitcoinExchange bit(av[1]);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	else {
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}
	return 0;
}
