#pragma once
#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include "ASpell.hpp"
#include <map>

class ASpell;

class SpellBook
{
	private:
	SpellBook(const SpellBook& ref);
	SpellBook& operator=(const SpellBook& ref);
	std::map < std::string, ASpell *> _SpellBook;
	public:
	SpellBook();
	~SpellBook();
	void learnSpell(ASpell*);
	void forgetSpell(std::string const &);
	ASpell* createSpell(std::string const &);
};

#endif
