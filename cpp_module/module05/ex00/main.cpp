/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:54:50 by huipark           #+#    #+#             */
/*   Updated: 2023/07/26 20:43:34 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

int main() {

	{
		std::cout << "-----------------Grade Row Test-----------------" << std::endl;
		try
		{
			Bureaucrat junkpark("junkpark", 150);
			std::cout << junkpark << std::endl;
			Bureaucrat huipark("huipark", 1);
			std::cout << huipark << std::endl;
			Bureaucrat jimpark("jimpark",149);
			std::cout << jimpark << std::endl;
			jimpark = huipark;
			std::cout << jimpark << std::endl;
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
}
