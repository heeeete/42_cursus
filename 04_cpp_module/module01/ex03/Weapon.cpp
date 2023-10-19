#include "Weapon.hpp"

Weapon::~Weapon() {}

void	Weapon::setType (std::string type) {
	this->type = type;
}

const std::string	&Weapon::getType( void ) const { return this->type; }
