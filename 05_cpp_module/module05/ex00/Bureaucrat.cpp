/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:54:57 by huipark           #+#    #+#             */
/*   Updated: 2023/08/14 19:58:25 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
		throw GradeTooHighException();
	--grade;
}

void Bureaucrat::decrement() {
	if (getGrade() == 150)
		throw GradeTooLowException();
	++grade;
}

std::ostream& operator<<(std::ostream &temp, const Bureaucrat& ref) {
	temp << ref.getName() << ", bureaucrat grade " << ref.getGrade();
	return temp;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& ref){
	if (this == &ref)
		return (*this);
	grade = ref.grade;
	return (*this);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
};

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
};
