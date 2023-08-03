/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:55:05 by huipark           #+#    #+#             */
/*   Updated: 2023/08/01 16:00:46 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"

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
			Bureaucrat huipark("huipakr", 1);
			RobotomyRequestForm qqqqq;
			qqqqq.beSigned(huipark);
			qqqqq.execute(huipark);

		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

	}
}
