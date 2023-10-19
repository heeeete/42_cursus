#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string _name;
	bool _signed;
	const int _gradeToSign;
	const int _gradeToExec;
public:
	Form();
	Form(const std::string name, int gradeToSign, int gradeToExec);
	Form(const Form& ref);
	~Form();

	const std::string& getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExec() const;

	void beSigned(const Bureaucrat& ref);

	Form& operator=(const Form& ref);

	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& temp, const Form& ref);

#endif
