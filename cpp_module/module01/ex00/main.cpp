#include "Zombie.hpp"

int main() {
	Zombie a("stack");
	Zombie	*heap = newZombie("heap");
	delete heap;
	randomChump("Chump");
}
