#include "SpellBook.hpp"

SpellBook::SpellBook() {}
SpellBook::~SpellBook() {}

void SpellBook::learnSpell(ASpell* ASpell){
	_SpellBook[ASpell->getName()] = ASpell;
}

void SpellBook::forgetSpell(std::string const & name){
	if (_SpellBook.find(name) != _SpellBook.end())
		_SpellBook.erase(_SpellBook.find(name));
}

ASpell* SpellBook::createSpell(std::string const &name) {
	ASpell* temp = NULL;
	if (_SpellBook.find(name) != _SpellBook.end())
		temp = _SpellBook[name];
	return temp;
}
