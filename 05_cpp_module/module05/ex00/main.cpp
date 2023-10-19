/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:54:50 by huipark           #+#    #+#             */
/*   Updated: 2023/08/14 19:49:23 by huipark          ###   ########.fr       */
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
			junkpark.decrement();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "-----------------Grade High Test-----------------" << std::endl;
		try
		{
			Bureaucrat huipark("huipark", 1);
			std::cout << huipark << std::endl;
			huipark.increment();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "-----------------Grade Row Test-----------------" << std::endl;
		try
		{
			Bureaucrat junkpark("junkpark", 151);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "-----------------Grade High Test-----------------" << std::endl;
		try
		{
			Bureaucrat huipark("huipark", 0);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}
