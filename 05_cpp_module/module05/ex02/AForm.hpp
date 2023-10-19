#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm
{
private:
	const std::string _name;
	bool _signed;
	const int _gradeToSign;
	const int _gradeToExec;
public:
	AForm();
	AForm(const std::string name, int gradeToSign, int gradeToExec);
	AForm(const AForm& ref);
	virtual ~AForm();

	const std::string& getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExec() const;

	void beSigned(const Bureaucrat& ref);
	virtual void execute(Bureaucrat const& executor) const = 0;

	AForm& operator=(const AForm& ref);

	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw();
	};

	class FormNotSignedException : public std::exception {
		public:
			virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& temp, const AForm& ref);

#endif
