#pragma once
#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>
#include <string>
#include "ASpell.hpp"

class ASpell;

class ATarget{
	private:
	std::string _type;

	public:
	ATarget();
	ATarget(std::string type);
	virtual ~ATarget();
	ATarget& operator=(const ATarget& ref);
	const std::string& getType() const;
	virtual ATarget* clone() const = 0;
	void getHitBySpell(const ASpell& ASpell) const;
};

#endif
