#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap() {
	name = ClapTrap::name;
	this->EnergyPoints = 50;
	ClapTrap::name += "_clap_name";
	std::cout << "NoName DiamondTrap was created defulat constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name), name(name) {
	this->EnergyPoints = 50;
	ClapTrap::name += "_clap_name";
	std::cout << name << " DiamondTrap was created by name constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap& ref) : ClapTrap(ref), ScavTrap(ref), FragTrap(ref), name(ref.name){
	std::cout << name << " DiamondTrap was created by copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << this->name << " Destructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& ref) {
	std::cout << "DiamondTrap " << "Copy assignment operator called" << std::endl;
	this->name = ref.name;
	this->HitPoints = ref.HitPoints;
	this->EnergyPoints = ref.EnergyPoints;
	this->AttackDamage = ref.AttackDamage;
	return *this;
}

void DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap name : " << this->name << std::endl;
	std::cout << "ClapTrap name : " << ClapTrap::name << std::endl;
}

void DiamondTrap::printStatus() {
	std::cout << "name : " << name << std::endl;
	std::cout << "HitPoints : " << HitPoints << std::endl;
	std::cout << "AttackDamage : " << AttackDamage << std::endl;
	std::cout << "EnergyPoints : " << EnergyPoints << std::endl;
	std::cout << "Clap name : " << ClapTrap::name << std::endl;
}
