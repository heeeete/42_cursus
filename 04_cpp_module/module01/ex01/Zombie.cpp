#include "Zombie.hpp"

Zombie::Zombie ( void ) {}

Zombie::Zombie(std::string name) {
	this->name = name;
	announce();
}

Zombie::~Zombie ( void ) {
	std::cout << name << " is die" << std::endl;
}

void	Zombie::setName(std::string name) {
	this->name = name;
	announce();
}

void	Zombie::announce( void ) {
	std::cout << name << " BraiiiiiiinnnzzzZ..." << std::endl;
}
