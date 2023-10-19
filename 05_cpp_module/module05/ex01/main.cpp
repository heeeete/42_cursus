#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try
	{
		std::cout << "----------------signForm test----------------" <<std::endl;
		Bureaucrat huipark("huipark", 1);
		Form form("form", 50, 50);
		huipark.signForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "----------------signForm Grade To Low test----------------" <<std::endl;
		Bureaucrat huipark("huipark", 51);
		Form form("form", 50, 50);
		huipark.signForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}
