#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	std::srand(time(NULL));
	{
		try
		{
			std::cout << "-------------RobotomyRequestForm Test-------------" << std::endl;
			Bureaucrat huipark("huipakr", 1);
			RobotomyRequestForm qqqqq;
			huipark.signForm(qqqqq);
			huipark.executeForm(qqqqq);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		try
		{
			std::cout << "-------------RobotomyRequestForm Grade To Low Test-------------" << std::endl;
			Bureaucrat huipark("huipakr", 140);
			RobotomyRequestForm qqqqq;
			huipark.signForm(qqqqq);
			huipark.executeForm(qqqqq);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		try
		{
			std::cout << "---------------ShrubberyCreationForm Test---------------" << std::endl;
			Bureaucrat huipark("huipark", 1);
			ShrubberyCreationForm a;
			huipark.signForm(a);
			huipark.executeForm(a);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		try
		{
			std::cout << "---------------ShrubberyCreationForm Grade To LowTest---------------" << std::endl;
			Bureaucrat huipark("huipark", 146);
			ShrubberyCreationForm a;
			huipark.signForm(a);
			huipark.executeForm(a);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		try
		{
			std::cout << "---------------PresidentialPardonForm Test---------------" << std::endl;
			Bureaucrat huipark("huipark", 1);
			PresidentialPardonForm a;
			huipark.signForm(a);
			huipark.executeForm(a);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		try
		{
			std::cout << "---------------PresidentialPardonForm Grade To LowTest---------------" << std::endl;
			Bureaucrat huipark("huipark", 146);
			PresidentialPardonForm a;
			huipark.signForm(a);
			huipark.executeForm(a);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}
