#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
	this->name = name;
	this->announce();
}

Zombie::~Zombie ( void ) {
	std::cout << name << " is die" << std::endl;
}

void	Zombie::announce( void ) {
	std::cout << name << " BraiiiiiiinnnzzzZ..." << std::endl;
}
