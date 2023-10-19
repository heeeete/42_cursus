#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(){}
TargetGenerator::~TargetGenerator(){}
void TargetGenerator::learnTargetType(ATarget* target){
	if (target) _target[target->getType()] = target;
}

void TargetGenerator::forgetTargetType(std::string const &name){
	if (_target.find(name) != _target.end())
		_target.erase(_target.find(name));
}

ATarget* TargetGenerator::createTarget(std::string const &name) {
	ATarget* temp = NULL;
	if (_target.find(name) != _target.end()) temp = _target[name];
	return temp;
}
