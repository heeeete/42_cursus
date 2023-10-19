#include "Brain.hpp"

Brain::Brain() { std::cout << "Brain constructor called" << std::endl;};
Brain::Brain(const Brain& ref) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = ref;
	};
Brain::~Brain()  {std::cout << "Brain destructor called" << std::endl;};
Brain&	Brain::operator=(const Brain& ref) {
	std::cout << "Brain assignation operator called" << std::endl;
	for (int i = 0 ; i < 100 ; i++) {
		this->ideas[i] = ref.ideas[i];
	}
	return *this;
}
