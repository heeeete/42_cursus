#include "PmergeMe.hpp"

int main(int ac, char *av[]){
	if (ac > 2){
		try
		{
			PmergeMe p(ac, av);
			p.sort();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	else {
		std::cout << "인자는 2개 이상의 숫자가 입력되어야 합니다.\n";
	}
}
