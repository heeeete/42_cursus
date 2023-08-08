#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), _target("default"){};
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
    : AForm(src), _target(src._target) {
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
        throw AForm::FormNotSignedException();
    } else if (executor.getGrade() > this->getGradeToExec()) {
        throw AForm::GradeTooLowException();
    } else {
        std::cout << "Drilling noises..." << std::endl;
        if (std::rand() % 2 == 0)
            std::cout << this->_target << " has been robotomized successfully"
                      << std::endl;
        else
            std::cout << "Robotomization failed" << std::endl;
    }
}
