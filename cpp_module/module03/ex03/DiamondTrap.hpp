#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string name;
public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(DiamondTrap& ref);
	~DiamondTrap();
	DiamondTrap&	operator=(const DiamondTrap& ref);
	void whoAmI();
	void printStatus();
};

#endif
