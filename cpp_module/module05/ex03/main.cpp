#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
	std::srand(time(NULL));
	{
		try
		{
			AForm* form;
			Intern intern;
			form = intern.makeForm("PresidentialPardonForm", "asd");
			// form->beSigned
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}
