#include "HumanB.hpp"

HumanB::~HumanB() {

}

void	HumanB::attack( void ) const {
	if (this->weapon == NULL)	std::cout << "No Weapon" << std::endl;
	else	std::cout << this->name << "is attack with a " << weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon){
	this->weapon = &weapon;
}
