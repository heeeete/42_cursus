#include "Intern.hpp"

Intern::Intern() {};
Intern::Intern(const Intern& ref) {
	*this = ref;
};
Intern::~Intern() {};

Intern& Intern::operator=(const Intern& ref) {
	(void)ref;
	return *this;
}

AForm* Intern::makeForm(std::string formName, std::string formTarget) {
	std::string formNames[3] = {"RobotomyRequestForm", "ShrubberyCreationForm", "PresidentialPardonForm"};

	int i = 0;
	for (; i < 3 ; i++) {
		if (formNames[i] == formName) {
			break ;
		}
	}

	switch (i)
	{
	case 0:
		std::cout << "Intern creates RobotomyRequestForm" << std::endl;
		return (new RobotomyRequestForm(formTarget));
	case 1:
		std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
		return (new ShrubberyCreationForm(formTarget));
	case 2:
		std::cout << "Intern creates PresidentialPardonForm" << std::endl;
		return (new PresidentialPardonForm(formTarget));
	default:
		throw Intern::CouldNotFindForm();
	}
}

const char* Intern::CouldNotFindForm::what() const throw(){
	return "Could not find form";
};
