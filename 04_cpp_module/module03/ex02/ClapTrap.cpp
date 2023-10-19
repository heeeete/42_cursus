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
	std::cout << "ClapTrap " << this->name << " Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (!this->HitPoints || !this->EnergyPoints) {
		std::cout << std::endl;
		if (!this->HitPoints && !this->EnergyPoints) std::cout << "ClapTrap " << this->name << " has no energy points and no hitpoints"<< std::endl;
		else if (!this->HitPoints) std::cout << "ClapTrap " << this->name << " has no hitpoints" << std::endl;
		else std::cout << "ClapTrap " << this->name << " has no energy points" << std::endl;
		std::cout << std::endl;
		return ;
	}
	std::cout << std::endl;
	std::cout << "ClapTrap " << this->name << " Hit " << this->AttackDamage << " Damage to " << target << std::endl;
	std::cout << std::endl;
	--this->EnergyPoints;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->HitPoints == 0) {
		std::cout << std::endl;
		std::cout << "ClapTrap " << this->name << "is dead..." << std::endl;
		std::cout << std::endl;
		return ;
	}
	else if (this->HitPoints <= amount) this->HitPoints = 0;
	else this->HitPoints -= amount;
	std::cout << std::endl;
	std:: cout << "ClapTrap " << this->name << " takes " << amount << " damage" << std::endl;
	std:: cout << "ClapTrap " << this->name << " HitPoints : " << this->HitPoints << std::endl;
	std::cout << std::endl;
	if (this->HitPoints == 0)	std::cout << "ClapTrap " << this->name << "is die..." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (!this->HitPoints || !this->EnergyPoints) {
		std::cout << std::endl;
		if (!this->HitPoints && !this->EnergyPoints) std::cout << "ClapTrap " << this->name << " has no energy points and no hitpoints"<< std::endl;
		else if (!this->HitPoints) std::cout << "ClapTrap " << this->name << " has no hitpoints" << std::endl;
		else std::cout << "ClapTrap " << this->name << " has no energy points" << std::endl;
		std::cout << std::endl;
		return ;
	}
	this->HitPoints += amount;
	--this->EnergyPoints;
	std::cout << std::endl;
	std::cout << "ClapTrap " << this->name << " Repairing" << std::endl;
	std::cout << "ClapTrap " << this->name << " takes " << amount << " Hitpoints" << std::endl;
	std:: cout << "ClapTrap " << this->name << " HitPoints : " << this->HitPoints << std::endl;
	std::cout << std::endl;
}

int	ClapTrap::getDamage() const {
	return this->AttackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& ref) {
	std::cout << "ClapTrap " << "Copy assignment operator called" << std::endl;
	this->name = ref.name;
	this->HitPoints = ref.HitPoints;
	this->EnergyPoints = ref.EnergyPoints;
	this->AttackDamage = ref.AttackDamage;
	return *this;
}
