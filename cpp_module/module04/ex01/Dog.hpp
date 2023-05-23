#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain* brain;
public:
	Dog();
	Dog(const Dog& ref);
	~Dog();
	Dog&	operator=(const Dog& ref);
	void	makeSound() const ;
};

#endif
