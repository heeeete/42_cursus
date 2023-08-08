#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:
public:
	Intern();
	Intern(const Intern& ref);
	~Intern();

	Intern& operator=(const Intern& ref);

	AForm* makeForm(std::string formName, std::string formTarget);

	class CouldNotFindForm : public std::exception {
		public :
			virtual const char* what() const throw();
	};
};

#endif
