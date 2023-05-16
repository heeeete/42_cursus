#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(){
	ScavTrap huitae("huitae");
	ScavTrap jimpark("jimpark");

	huitae.attack("jimpark");
	jimpark.takeDamage(huitae.getDamage());
	jimpark.beRepaired(1);
	huitae.attack("jimpark");
	jimpark.takeDamage(8);
	huitae.attack("jimpark");
	jimpark.takeDamage(huitae.getDamage());
}
