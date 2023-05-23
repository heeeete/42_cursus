#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	type= "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& ref) {
	*this = ref;
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat() { std::cout << "WrongCat destructor called" << std::endl; }

WrongCat& WrongCat::operator=(const WrongCat& ref){
	std::cout << "WrongCat assignation operator called" << std::endl;
	this->type = ref.type;
	return *this;
}

void WrongCat::makeSound() const {
  std::cout << "Meow~ Meow~" << std::endl;
}
