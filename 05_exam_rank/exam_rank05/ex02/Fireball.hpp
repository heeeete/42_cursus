#pragma once
#ifndef FIREBALL_HPP
#define FIREBALL_HPP

#include "ASpell.hpp"

class ASpell;

class Fireball : public ASpell
{
	public:
	Fireball();
	virtual ~Fireball();
	virtual ASpell* clone() const;
};

#endif
