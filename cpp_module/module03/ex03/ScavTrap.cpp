#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
	std::cout << "NoName ScavTrap was created defulat constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
	std::cout << name << " ScavTrap was created by name constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap& ref) : ClapTrap(ref) {
	std::cout << name << " ScavTrap was created by copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->name << " Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (!this->HitPoints || !this->EnergyPoints) {
		std::cout << std::endl;
		if (!this->HitPoints && !this->EnergyPoints) std::cout << "ScavTrap " << this->name << " has no energy points and no hitpoints"<< std::endl;
		else if (!this->HitPoints) std::cout << "ScavTrap " << this->name << " has no hitpoints" << std::endl;
		else std::cout << "ScavTrap " << this->name << " has no energy points" << std::endl;
		std::cout << std::endl;
		return ;
	}
	std::cout << std::endl;
	std::cout << "ScavTrap " << this->name << " Hit " << this->AttackDamage << " Damage to " << target << std::endl;
	std::cout << std::endl;
	--this->EnergyPoints;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& ref) {
	std::cout << "ScavTrap " << "Copy assignment operator called" << std::endl;
	this->name = ref.name;
	this->HitPoints = ref.HitPoints;
	this->EnergyPoints = ref.EnergyPoints;
	this->AttackDamage = ref.AttackDamage;
	return *this;
}

void	ScavTrap::guardGate() {
	if (!this->HitPoints || !this->EnergyPoints) {
		std::cout << std::endl;
		if (!this->HitPoints && !this->EnergyPoints) std::cout << "ScavTrap " << this->name << " has no energy points and no hitpoints"<< std::endl;
		else if (!this->HitPoints) std::cout << "ScavTrap " << this->name << " has no hitpoints" << std::endl;
		else std::cout << "ScavTrap " << this->name << " has no energy points" << std::endl;
		std::cout << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->name << " has entered gate guard mode" << std::endl;
	this->EnergyPoints--;
}
