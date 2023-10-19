/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:54:36 by huipark           #+#    #+#             */
/*   Updated: 2023/08/14 19:57:42 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExec(150) {};
Form::Form(const std::string name, int gradeToSign, int gradeToExec) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	if (_gradeToSign < 1 || _gradeToExec < 1) {
		std::cout << _name << ", ";
		throw GradeTooHighException();
	}
	else if (_gradeToSign > 150 || _gradeToExec > 150) {
		std::cout << _name << ", ";
		throw GradeTooLowException();
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

void Form::beSigned(const Bureaucrat& ref) {
	if (ref.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	else
		_signed = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
};

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
};

Form& Form::operator=(const Form& ref){
	if (this == &ref)
		return (*this);
	_signed = ref._signed;
	return (*this);
}

std::ostream& operator<<(std::ostream& temp, const Form& ref) {
	temp << ref.getName() << ", "
	 << std::boolalpha << "Signed : " << ref.getSigned() << ", "
	 << "GradeToSign : " << ref.getGradeToSign() << ", "
	 << "GradeToExecute : " << ref.getGradeToExec() << std::endl;
	return (temp);
}
