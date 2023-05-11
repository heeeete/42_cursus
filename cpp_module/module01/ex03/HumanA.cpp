#include "HumanA.hpp"

HumanA::~HumanA() {

}

void	HumanA::attack( void ) const {
	std::cout << this->name << "is attack with a " << weapon.getType() << std::endl;
}
