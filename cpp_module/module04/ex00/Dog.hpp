#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
private:

public:
	Dog();
	Dog(const Dog& ref);
	~Dog();
	Dog&	operator=(const Dog& ref);
	void	makeSound() const ;
};

#endif
