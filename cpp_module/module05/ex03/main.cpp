/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:55:05 by huipark           #+#    #+#             */
/*   Updated: 2023/08/07 17:08:53 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	std::srand(time(NULL));
	{
		std::cout << "-----------------Grade Row Test-----------------" << std::endl;
		try
		{
			Bureaucrat junkpark("junkpark", 150);
			std::cout << junkpark << std::endl;
			Bureaucrat huipark("huipark", 1);
			std::cout << huipark << std::endl;
			Bureaucrat jimpark("jimpark",149);
			Bureaucrat hyunjki("hyunjki", 0);
			std::cout << hyunjki << std::endl;
		}
		catch(const std::range_error& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "-----------------Grade High Test-----------------" << std::endl;
		try
		{
			Bureaucrat junkpark("junkpark", 150);
			std::cout << junkpark << std::endl;
			Bureaucrat huipark("huipark", 1);
			std::cout << huipark << std::endl;
			Bureaucrat jimpark("jimpark",149);
			std::cout << jimpark << std::endl;
			Bureaucrat hyunjki("hyunjki", 151);
			std::cout << hyunjki << std::endl;
		}
		catch(const std::range_error& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		try
		{
			std::cout << "-------------RobotomyRequestForm Test-------------" << std::endl;
			Bureaucrat huipark("huipakr", 1);
			RobotomyRequestForm qqqqq;
			RobotomyRequestForm b(qqqqq);
			b.beSigned(huipark);
			b.execute(huipark);
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
			ShrubberyCreationForm form("huiparkForm2123123123");
			ShrubberyCreationForm form3("!@#!@#!!@#!@#!@#!@#");
			ShrubberyCreationForm form2(form);
			form2 = form3;
			ShrubberyCreationForm a;
			a.beSigned(huipark);
			a.execute(huipark);
			form2.beSigned(huipark);
			form2.execute(huipark);
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
			Bureaucrat asd("asd", 25);
			PresidentialPardonForm haaui("huipark");
			PresidentialPardonForm a(haaui);
			a = haaui;
			a.beSigned(asd);
			a.execute(huipark);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}
