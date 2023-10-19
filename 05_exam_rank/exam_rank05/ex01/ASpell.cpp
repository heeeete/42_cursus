#include "ASpell.hpp"

ASpell::ASpell() {}
ASpell::ASpell(std::string name, std::string effects) : _name(name), _effects(effects){}
ASpell::~ASpell(){}
ASpell& ASpell::operator=(const ASpell& ref){
	if (this != &ref){
		_name = ref._name;
		_effects = ref._effects;
		return (*this);
	}
	return *this;
}

std::string ASpell::getName() const{
	return _name;
}

std::string ASpell::getEffects() const{
	return _effects;
}

void ASpell::launch(const ATarget& ATarget) const{
	ATarget.getHitBySpell(*this);
}
