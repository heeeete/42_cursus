#include "Dog.hpp"

Dog::Dog() : Animal() {
	type= "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& ref) {
	*this = ref;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog() { std::cout << "Dog destructor called" << std::endl; }

Dog& Dog::operator=(const Dog& ref){
	std::cout << "Dog assignation operator called" << std::endl;
	this->type = ref.type;
	return *this;
}

void Dog::makeSound() const {
  std::cout << "Bowwow~ Bowwow~" << std::endl;
}
