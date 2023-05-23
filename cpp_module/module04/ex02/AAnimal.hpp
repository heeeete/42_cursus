#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>

class AAnimal
{
protected:
	std::string type;
public:
	AAnimal();
	AAnimal(const AAnimal& obj);
	AAnimal& operator=(const AAnimal& obj);
	virtual ~AAnimal();
	virtual void	makeSound() const ;
	std::string		getType() const;
};

#endif
