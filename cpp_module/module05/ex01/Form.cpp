/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:54:36 by huipark           #+#    #+#             */
/*   Updated: 2023/07/26 21:22:18 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExec(150) {};
Form::Form(const std::string name, int gradeToSign, int gradeToExec) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	if (_gradeToSign < 1 || _gradeToExec < 1) {
		std::cout << "Name : " << _name << std::endl;

		if (_gradeToSign < 1)	std::cout << "your GradeToSign : " << _gradeToSign << std::endl;
		else	std::cout << "your GradeToExec : " << _gradeToExec << std::endl;\

		std::cout << "1 <= value <= 150" << _name << std::endl;
		GradeTooLowException();
	}
	else if (_gradeToSign > 150 || _gradeToExec > 150) {
		std::cout << "Name : " << _name << std::endl;

		if (_gradeToSign > 150)	std::cout << "your GradeToSign : " << _gradeToSign << std::endl;
		else	std::cout << "your GradeToExec : " << _gradeToExec << std::endl;\

		std::cout << "1 <= value <= 150" << _name << std::endl;
		GradeTooHighException();
	}
};
Form::Form(const Form& ref) : _name(ref._name), _signed(ref._signed), _gradeToSign(ref._gradeToSign), _gradeToExec(ref._gradeToExec) {};
Form::~Form() {};

const std::string& Form::getName() const {
	return (_name);
};

bool Form::getSigned() const {
	return (_signed);
};

int Form::getGradeToSign() const {
	return (_gradeToSign);
}

int Form::getGradeToExec() const {
	return (_gradeToExec);
}

std::range_error Form::GradeTooHighException() const{
	throw ("Grade Too High");
}

std::range_error Form::GradeTooLowException() const{
	throw ("Grade Too Low");
}

Form& Form::operator=(const Form& ref){
	if (this == &ref)
		return (*this);
	_signed = ref._signed;
	return (*this);
}

std::ostream& operator<<(std::ostream& temp, const Form& ref) {
	temp << "Name : " << ref.getName() << std::endl;
	temp << "Signed : " << ref.getSigned() << std::endl;
	temp << "GradeToSign : " << ref.getGradeToSign() << std::endl;
	temp << "GradeToExecute : " << ref.getGradeToExec() << std::endl;
}
