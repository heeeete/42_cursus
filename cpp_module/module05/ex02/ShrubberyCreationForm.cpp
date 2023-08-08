/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:09:05 by huipark           #+#    #+#             */
/*   Updated: 2023/08/08 15:33:10 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default") {};
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {};
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm(src), _target(src._target){};
ShrubberyCreationForm::~ShrubberyCreationForm() {};

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& ref){
	if (this == &ref)
		return *this;
	_target = ref._target;
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (!getSigned()) {
        throw AForm::FormNotSignedException();
    } else if (executor.getGrade() > this->getGradeToExec()) {
        throw AForm::GradeTooLowException();
    } else {
		std::string			shrubbery =	"               ,@@@@@@@,\n"
							   						"       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
							   						"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
							   						"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
							   						"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
							   						"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
							   						"   `&%\\ ` /%&'    |.|        \\ '|8'\n"
							   						"       |o|        | |         | |\n"
							   						"       |.|        | |         | |\n"
							   						"    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n";
		std::ofstream file;
		file.open(_target + "_shrubbery ");
		if (file.is_open()){
			file << shrubbery;
			file.close();
		}
		else
			throw ShrubberyCreationForm::FileOpenError();
    }
}

const char* ShrubberyCreationForm::FileOpenError::what() const throw() {
	return "file open error";
}

