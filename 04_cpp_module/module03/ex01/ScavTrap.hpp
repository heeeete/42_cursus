#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(ScavTrap& ref);
	~ScavTrap();
	ScavTrap&	operator=(const ScavTrap& ref);
	void		attack(const std::string& target);
	void		guardGate();
};

#endif
