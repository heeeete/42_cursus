#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {std::cout << "WrongAnimal constructor called" << std::endl;};
WrongAnimal::~WrongAnimal(){std::cout << "WrongAnimal destructor called" << std::endl;};
WrongAnimal::WrongAnimal(const WrongAnimal& obj) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = obj;
};
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj) {
	std::cout << "WrongAnimal assignation operator called" << std::endl;
	type = obj.type;
	return *this;
}

void WrongAnimal::makeSound() const{
	std::cout << "WrongAnimal Sound" << std::endl;
}

std::string WrongAnimal::getType() const{
	return type;
}
