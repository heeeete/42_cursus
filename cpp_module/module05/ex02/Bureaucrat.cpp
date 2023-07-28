/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:54:44 by huipark           #+#    #+#             */
/*   Updated: 2023/07/28 19:47:26 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150) {};
Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade) {
	if (grade < 1)
	{
		std::cout << name << ", "
		<< "your grade : " << grade << ", ";
		GradeTooHighException();
	}
	else if (grade > 150)
	{
		std::cout << name << ", "
		<< "your grade : " << grade << ", ";
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

void Bureaucrat::signForm(Form& form) {
  try {
    form.beSigned(*this);
    std::cout << name << " signed " << form.getName() << std::endl;
  } catch (std::exception& e) {
    std::cout << name << " couldn\\'t sign " << form.getName() << " because "
              << e.what() << std::endl;
  }
}

std::ostream& operator<<(std::ostream &temp, const Bureaucrat& ref) {
	temp << ref.getName() << ", bureaucrat grade " << ref.getGrade();
	return temp;
}

std::range_error Bureaucrat::GradeTooHighException() const{
  throw (std::range_error("Grade too high : 1 <= Grade <= 150"));
}

std::range_error Bureaucrat::GradeTooLowException() const{
  throw (std::range_error("Grade too low : 1 <= Grade <= 150"));
}
