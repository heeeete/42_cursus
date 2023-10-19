#include "Warlock.hpp"

Warlock::Warlock(std::string name, std::string title) : _name(name), _title(title) {
	std::cout << _name << ": This looks like another boring day." << std::endl;
};

Warlock::~Warlock() {
	std::cout << _name << ": My job here is done!" << std::endl;
};

const std::string&		Warlock::getName(void) const {
	return this->_name;
};

const std::string&		Warlock::getTitle(void) const {
	return this->_title;
};

void	Warlock::setTitle(const std::string& title) {
	this->_title = title;
};

void	Warlock::introduce() const {
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
};
