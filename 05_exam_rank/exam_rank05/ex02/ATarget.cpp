#include "ATarget.hpp"

ATarget::ATarget(){}
ATarget::ATarget(std::string type): _type(type){}
ATarget::~ATarget(){}
ATarget& ATarget::operator=(const ATarget& ref){
	if (this != &ref)
	{
		_type = ref._type;
	}
	return *this;
}

const std::string& ATarget::getType() const {
	return _type;
}

void ATarget::getHitBySpell(const ASpell& ASpell) const {
	std::cout << _type << " has been " << ASpell.getEffects() << "!\n";
}

