/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:54:06 by huipark           #+#    #+#             */
/*   Updated: 2023/08/01 16:00:39 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), _target("default"){};
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
    : AForm(src), _target(src._target) {
    *this = src;
}
RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {}
RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& ref){
	if (this == &ref)
		return *this;
	_target = ref._target;
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    if (!getSigned()) {
        throw FormNotSignedException();
    } else if (executor.getGrade() > this->getGradeToExec()) {
        throw GradeTooLowException();
    } else {
		std::cout << std::rand() << std::endl;
        std::cout << "Drilling noises..." << std::endl;
        if (std::rand() % 2 == 0)
            std::cout << this->_target << " has been robotomized successfully"
                      << std::endl;
        else
            std::cout << "Robotomization failed" << std::endl;
    }
}
