/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:54:57 by huipark           #+#    #+#             */
/*   Updated: 2023/07/28 17:53:00 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150) {};
Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade) {
	if (grade < 1)
	{
		std::cout << "your name : " << name << std::endl;
		std::cout << "your grade : " << grade << std::endl;
		GradeTooHighException();
	}
	else if (grade > 150)
	{
		std::cout << "your name : " << name << std::endl;
		std::cout << "your grade : " << grade << std::endl;
		GradeTooLowException();
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

std::range_error Bureaucrat::GradeTooHighException() const{
  throw (std::range_error("Grade too high : 1 <= Grade <= 150"));
}

std::range_error Bureaucrat::GradeTooLowException() const{
  throw (std::range_error("Grade too low : 1 <= Grade <= 150"));
}
