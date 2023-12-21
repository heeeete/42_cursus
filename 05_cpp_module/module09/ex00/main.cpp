#include <iostream>
#include "BitcoinExchange.hpp"

int main(int ac, char **av){
	if (ac == 3){
		try
		{
			BitcoinExchange bit(av[1], av[2]);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	else {
		std::cout << "example $./bit (data) (bit-coin data)" << std::endl;
		return 1;
	}
	return 0;
}
