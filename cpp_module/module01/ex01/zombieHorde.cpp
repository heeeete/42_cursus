#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
	Zombie	*Legion = new Zombie[N];
	std::stringstream	ss;
	std::string			num;
	for (int i = 0; i < N; i++) {
		ss << i;
		num = ss.str();
		ss.str("");
		Legion[i].setName(name + num);
	}
	return Legion;
}
