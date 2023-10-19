#include "Zombie.hpp"

int main(){
	Zombie	*legion = zombieHorde(10, "huipark");
	Zombie	stack("stack");
	delete[] legion;
}
