#include "Cat.hpp"

Cat::Cat() : Animal() {
	type= "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& ref) {
	*this = ref;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat() { std::cout << "Cat destructor called" << std::endl; }

Cat& Cat::operator=(const Cat& ref){
	std::cout << "Cat assignation operator called" << std::endl;
	this->type = ref.type;
	return *this;
}

void Cat::makeSound() const {
  std::cout << "Meow~ Meow~" << std::endl;
}
