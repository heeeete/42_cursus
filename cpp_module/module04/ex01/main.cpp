#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
	Animal *meta[10];

	for (size_t i = 0; i < 10; i++)
	{
		if (i % 2)
		{
			meta[i] = new Dog();
		}
		else
		{
			meta[i] = new Cat();
		}
	}
	std::cout << std::endl;

	meta[0]->makeSound();
	meta[1]->makeSound();
	for (size_t i = 0; i < 10; i++)
	{
		delete meta[i];
	}
	system("leaks ex01");
  return 0;
}
