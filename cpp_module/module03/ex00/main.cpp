#include "ClapTrap.hpp"

int main(){
	ClapTrap huitae("huitae");
	ClapTrap jimpark("jimpark");

	huitae.attack("jimpark");
	jimpark.takeDamage(3);
	jimpark.beRepaired(1);
	huitae.attack("jimpark");
	jimpark.takeDamage(8);
	huitae.attack("jimpark");
	jimpark.takeDamage(8000);
}
