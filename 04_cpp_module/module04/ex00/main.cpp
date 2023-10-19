#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
std::cout << "--------------1--------------" << std::endl;
const Animal* ANIMAL = new Animal();
std::cout << "type : " << ANIMAL->getType() << std::endl;
ANIMAL->makeSound();
delete ANIMAL;
std::cout << "-----------------------------" << std::endl;
std::cout << "--------------2--------------" << std::endl;
const Animal* DOG = new Dog();
std::cout << "type : " << DOG->getType() << std::endl;
DOG->makeSound();
delete DOG;
std::cout << "-----------------------------" << std::endl;
std::cout << "--------------3--------------" << std::endl;
const Animal* CAT = new Cat();
std::cout << "type : " << CAT->getType() << std::endl;
CAT->makeSound();
delete CAT;
std::cout << "-----------------------------" << std::endl;
std:: cout << std::endl << std::endl << "	WRONG	" << std::endl;
std::cout << "--------------1--------------" << std::endl;
const WrongAnimal* W_ANIMAL = new WrongAnimal();
std::cout << "type : " << W_ANIMAL->getType() << std::endl;
W_ANIMAL->makeSound();
delete W_ANIMAL;
std::cout << "-----------------------------" << std::endl;
std::cout << "--------------2--------------" << std::endl;
const WrongAnimal* W_CAT = new WrongCat();
std::cout << "type : " << W_CAT->getType() << std::endl;
W_CAT->makeSound();
delete W_CAT;
std::cout << "-----------------------------" << std::endl;
return 0;
}
