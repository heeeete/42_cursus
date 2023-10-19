#pragma once
#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>
#include <string>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
	private:
	std::string _name;
	std::string _effects;

	public:
	ASpell();
	ASpell(std::string name, std::string effects);
	virtual ~ASpell();
	ASpell& operator=(const ASpell& ref);
	std::string getName() const;
	std::string getEffects() const;
	virtual ASpell* clone() const = 0;
	void launch(const ATarget& ATarget) const;
};

#endif
