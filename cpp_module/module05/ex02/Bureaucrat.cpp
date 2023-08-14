/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:54:44 by huipark           #+#    #+#             */
/*   Updated: 2023/08/14 20:00:55 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150) {};
Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade) {
	if (grade < 1)
	{
		std::cout << name << ", " ;
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > 150)
	{
		std::cout << name << ", " ;
		throw Bureaucrat::GradeTooLowException();
	}
};
Bureaucrat::Bureaucrat(const Bureaucrat& ref) :name(ref.name), grade(ref.grade) {};
Bureaucrat::~Bureaucrat(){};

const std::string& Bureaucrat::getName() const{
	return (name);
}
int Bureaucrat::getGrade() const{
	return (grade);
}

void Bureaucrat::increment() {
	if (getGrade() == 1)
		throw Bureaucrat::GradeTooHighException();
	--grade;
}

void Bureaucrat::decrement() {
	if (getGrade() == 150)
		throw Bureaucrat::GradeTooLowException();
	++grade;
}

void Bureaucrat::executeForm(AForm const & form) {
	try {
	form.execute(*this);
	std::cout << name << " executed " << form.getName() << std::endl;
	} catch (std::exception& e) {
	std::cout << name << " couldn’t execute " << form.getName() << " because "
			  << e.what() << std::endl;
	}
}

void Bureaucrat::signForm(AForm& form) {
	try {
	form.beSigned(*this);
	std::cout << name << " signed " << form.getName() << std::endl;
	} catch (std::exception& e) {
	std::cout << name << " couldn't sign " << form.getName() << " because "
			  << e.what() << std::endl;
	}
}


std::ostream& operator<<(std::ostream &temp, const Bureaucrat& ref) {
	temp << ref.getName() << ", bureaucrat grade " << ref.getGrade();
	return temp;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
};

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
};
