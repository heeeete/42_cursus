#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	this->HitPoints = 100;
	this->EnergyPoints = 100;
	this->AttackDamage = 30;
	std::cout << "NoName FragTrap was created defulat constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->HitPoints = 100;
	this->EnergyPoints = 100;
	this->AttackDamage = 30;
	std::cout << name << " FragTrap was created by name constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap& ref) : ClapTrap(ref) {
	std::cout << name << " FragTrap was created by copy constructor called" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->name << " Destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& ref) {
	std::cout << "FragTrap " << "Copy assignment operator called" << std::endl;
	this->name = ref.name;
	this->HitPoints = ref.HitPoints;
	this->EnergyPoints = ref.EnergyPoints;
	this->AttackDamage = ref.AttackDamage;
	return *this;
}

void FragTrap::highFivesGuys(void) {
	if (!this->HitPoints) {
		std::cout << "FragTrap " << this->name << " is dead..." << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->name << " high five!!!" << std::endl;
}
