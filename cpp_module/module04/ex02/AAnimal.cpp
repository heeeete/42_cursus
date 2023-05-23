#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal") {std::cout << "AAnimal constructor called" << std::endl;};
AAnimal::~AAnimal(){std::cout << "AAnimal destructor called" << std::endl;};
AAnimal::AAnimal(const AAnimal& obj) {
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = obj;
};
AAnimal& AAnimal::operator=(const AAnimal& obj) {
	std::cout << "AAnimal assignation operator called" << std::endl;
	type = obj.type;
	return *this;
}

void AAnimal::makeSound() const{
	std::cout << "AAnimal Sound" << std::endl;
}

std::string AAnimal::getType() const{
	return type;
}
