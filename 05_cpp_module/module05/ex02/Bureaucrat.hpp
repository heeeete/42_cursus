#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class AForm;

class Bureaucrat
{
private:
	const std::string name;
	int grade;
public:
	Bureaucrat();
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat& ref);
	~Bureaucrat();

	const std::string& getName() const;
	int getGrade() const;

	void increment();
	void decrement();
	void executeForm(AForm const & form);
	void signForm(AForm& form);

	Bureaucrat& operator=(const Bureaucrat& ref);

	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream &temp, const Bureaucrat& ref);

#endif
