#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default") {};
PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {};
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : AForm(src), _target(src._target) {};
PresidentialPardonForm::~PresidentialPardonForm() {};

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	if (!getSigned()) {
        throw AForm::FormNotSignedException();
    } else if (executor.getGrade() > this->getGradeToExec()) {
        throw AForm::GradeTooLowException();
    } else {
		std::cout << executor.getName() << " has been pardoned by Zafod Beeblebrox"
              << std::endl;
	}
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& ref){
	if (this == &ref)
		return *this;
	_target = ref._target;
	return *this;
}
