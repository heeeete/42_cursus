#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
	std::srand(time(NULL));
	{
		try
		{
			AForm* form;
			Bureaucrat huipark("huipakr", 1);
			Intern intern;
			form = intern.makeForm("PresidentialPardonForm", "asd");
			delete form;
			form = intern.makeForm("RobotomyRequestForm", "asd");
			huipark.signForm(*form);
			huipark.executeForm(*form);
			delete form;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		try
		{
			std::cout <<"---------------Grade To Low---------------" << std::endl;
			AForm* form;
			Bureaucrat huipark("huipakr", 146);
			Intern intern;
			form = intern.makeForm("PresidentialPardonForm", "asd");
			delete form;
			form = intern.makeForm("RobotomyRequestForm", "asd");
			huipark.signForm(*form);
			huipark.executeForm(*form);
			delete form;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}
