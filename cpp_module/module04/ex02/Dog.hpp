#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
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
