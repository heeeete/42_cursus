#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>
#include <map>
#include "ASpell.hpp"

class Warlock;

class Warlock
{
	private :
		std::string _name;
		std::string _title;
		Warlock();
		Warlock(const Warlock& ref);
		Warlock& operator=(const Warlock& ref);
		std::map < std::string, ASpell * > _SpellBook;
	public :
		Warlock(std::string name, std::string title);
		~Warlock();
		const std::string& getName() const;
		const std::string& getTitle() const;
		void setTitle(const std::string& title);
		void introduce() const;
		void learnSpell(ASpell* ASpell);
		void forgetSpell(std::string name);
		void launchSpell(std::string name, ATarget& ATarget);
};

#endif
