#include "Animal.hpp"

Animal::Animal() : type("Animal") {std::cout << "Animal constructor called" << std::endl;};
Animal::~Animal(){std::cout << "Animal destructor called" << std::endl;};
Animal::Animal(const Animal& obj) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = obj;
};
Animal& Animal::operator=(const Animal& obj) {
	std::cout << "Animal assignation operator called" << std::endl;
	type = obj.type;
	return *this;
}

void Animal::makeSound() const{
	std::cout << "Animal Sound" << std::endl;
}

std::string Animal::getType() const{
	return type;
}
