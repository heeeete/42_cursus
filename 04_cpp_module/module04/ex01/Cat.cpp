#include "Cat.hpp"

Cat::Cat() : Animal() {
	type= "Cat";
	std::cout << "Cat constructor called" << std::endl;
	brain = new Brain();
}

Cat::Cat(const Cat& ref) {
	std::cout << "Cat copy constructor called" << std::endl;
	brain = new Brain();
	*this = ref;
}

Cat::~Cat() {
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& ref){
	std::cout << "Cat assignation operator called" << std::endl;
	this->type = ref.type;
	*this->brain = *ref.brain;
	return *this;
}

void Cat::makeSound() const {
  std::cout << "Meow~ Meow~" << std::endl;
}
