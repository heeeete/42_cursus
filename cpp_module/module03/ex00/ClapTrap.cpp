#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("NoName"), HitPoints(10), EnergyPoints(10), AttackDamage(0) {
	std::cout << "NoName ClapTrap was created defulat constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), HitPoints(10), EnergyPoints(10), AttackDamage(0) {
	std::cout << name << " ClapTrap was created by name constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap& ref) : name(ref.name), HitPoints(ref.HitPoints), EnergyPoints(ref.EnergyPoints), AttackDamage(ref.AttackDamage) {
	std::cout << name << " ClapTrap was created by copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << this->name << " Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (!this->HitPoints || !this->EnergyPoints) {
		if (!this->HitPoints && !this->EnergyPoints) std::cout << this->name << " has no energy points and no hitpoints"<< std::endl;
		else if (!this->HitPoints) std::cout << this->name << " has no hitpoints" << std::endl;
		else std::cout << this->name << " has no energy points" << std::endl;
		return ;
	}
	std::cout << this->name << " Hit " << this->AttackDamage << " Damage to " << target << std::endl;
	--this->EnergyPoints;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->HitPoints == 0) {
		std::cout << this->name << "is dead..." << std::endl;
		return ;
	}
	else if (this->HitPoints <= amount) this->HitPoints = 0;
	else this->HitPoints -= amount;
	std:: cout << this->name << " takes " << amount << " damage" << std::endl;
	std:: cout << this->name << " HitPoints : " << this->HitPoints << std::endl;
	if (this->HitPoints == 0)	std::cout << this->name << "is die..." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (!this->HitPoints || !this->EnergyPoints) {
		if (!this->HitPoints && !this->EnergyPoints) std::cout << this->name << " has no energy points and no hitpoints"<< std::endl;
		else if (!this->HitPoints) std::cout << this->name << " has no hitpoints" << std::endl;
		else std::cout << this->name << " has no energy points" << std::endl;
		return ;
	}
	this->HitPoints += amount;
	--this->EnergyPoints;
	std::cout << this->name << " Repairing" << std::endl;
	std::cout << this->name << " takes " << amount << " Hitpoints" << std::endl;
	std:: cout << this->name << " HitPoints : " << this->HitPoints << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& ref) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->name = ref.name;
	this->HitPoints = ref.HitPoints;
	this->EnergyPoints = ref.EnergyPoints;
	this->AttackDamage = ref.AttackDamage;
	return *this;
}
