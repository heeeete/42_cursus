#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
std::cout << "--------------DOG--------------" << std::endl;
const AAnimal* DOG = new Dog();
std::cout << "type : " << DOG->getType() << std::endl;
DOG->makeSound();
delete DOG;
std::cout << "-----------------------------" << std::endl;
std::cout << "--------------CAT--------------" << std::endl;
const AAnimal* CAT = new Cat();
std::cout << "type : " << CAT->getType() << std::endl;
CAT->makeSound();
delete CAT;
std::cout << "-----------------------------" << std::endl;
return 0;
}
