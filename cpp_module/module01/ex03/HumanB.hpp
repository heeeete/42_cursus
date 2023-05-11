#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private:
		std::string	name;
		Weapon		*weapon;
	public:
		HumanB(std::string name) : name(name), weapon(nullptr) {}
		~HumanB();
		void	attack( void ) const ;
		void	setWeapon(Weapon &weapon);
};

#endif
