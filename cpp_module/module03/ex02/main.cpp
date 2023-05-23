#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main(){
	FragTrap huitae("huitae");
	FragTrap jimpark("jimpark");

	huitae.attack("jimpark");
	jimpark.takeDamage(huitae.getDamage());
	jimpark.beRepaired(1);
	huitae.attack("jimpark");
	jimpark.takeDamage(huitae.getDamage());
	huitae.attack("jimpark");
	jimpark.takeDamage(huitae.getDamage());
	huitae.attack("jimpark");
	jimpark.takeDamage(huitae.getDamage());
	huitae.attack("jimpark");
	jimpark.takeDamage(huitae.getDamage());
	huitae.attack("jimpark");
	jimpark.takeDamage(huitae.getDamage());
	huitae.attack("jimpark");
	jimpark.takeDamage(huitae.getDamage());
	huitae.attack("jimpark");
	jimpark.takeDamage(huitae.getDamage());
	jimpark.highFivesGuys();
	huitae.highFivesGuys();
}
