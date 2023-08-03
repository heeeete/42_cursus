/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:54:36 by huipark           #+#    #+#             */
/*   Updated: 2023/08/01 15:42:49 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExec(150) {};
AForm::AForm(const std::string name, int gradeToSign, int gradeToExec) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	if (_gradeToSign < 1 || _gradeToExec < 1) {
		std::cout << _name << ", ";

		if (_gradeToSign < 1)	std::cout << "your GradeToSign : " << _gradeToSign << ", ";
		else	std::cout << "your GradeToExec : " << _gradeToExec << ", ";

		std::cout << "1 <= value <= 150" << ", ";
		GradeTooHighException();
	}
	else if (_gradeToSign > 150 || _gradeToExec > 150) {
		std::cout << _name << ", ";

		if (_gradeToSign > 150)	std::cout << "your GradeToSign : " << _gradeToSign << ", ";
		else	std::cout << "your GradeToExec : " << _gradeToExec << ", ";

		std::cout << "1 <= value <= 150" << ", ";
		GradeTooLowException();
	}
};
AForm::AForm(const AForm& ref) : _name(ref._name), _signed(ref._signed), _gradeToSign(ref._gradeToSign), _gradeToExec(ref._gradeToExec) {};
AForm::~AForm() {};

const std::string& AForm::getName() const {
	return (_name);
};

bool AForm::getSigned() const {
	return (_signed);
};

int AForm::getGradeToSign() const {
	return (_gradeToSign);
}

int AForm::getGradeToExec() const {
	return (_gradeToExec);
}

void AForm::beSigned(const Bureaucrat& ref) {
	if (ref.getGrade() > _gradeToSign){
		std::cout << "your grade is " << ref.getGrade() << ", gradeToSign is " << _gradeToSign << ", ";
		GradeTooLowException();
	}
	else
		_signed = true;
}

std::range_error AForm::GradeTooHighException() const{
	throw (std::range_error("Grade Too High"));
}

std::range_error AForm::GradeTooLowException() const{
	throw (std::range_error("Grade Too Low"));
}

std::runtime_error AForm::FormNotSignedException() const {
    return std::runtime_error("Form is not signed");
}

AForm& AForm::operator=(const AForm& ref){
	if (this == &ref)
		return (*this);
	_signed = ref._signed;
	return (*this);
}

std::ostream& operator<<(std::ostream& temp, const AForm& ref) {
	temp << ref.getName() << ", "
	 << std::boolalpha << "Signed : " << ref.getSigned() << ", "
	 << "GradeToSign : " << ref.getGradeToSign() << ", "
	 << "GradeToExecute : " << ref.getGradeToExec() << std::endl;
	return (temp);
}
