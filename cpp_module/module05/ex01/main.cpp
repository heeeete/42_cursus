/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:55:05 by huipark           #+#    #+#             */
/*   Updated: 2023/08/08 15:07:03 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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
			Form a("a", 2, 2);
			huipark.signForm(a);
			jimpark.signForm(a);
			Bureaucrat hyunjki("hyunjki", 0);
			std::cout << hyunjki << std::endl;
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
			Bureaucrat junkpark("junkpark", 150);
			std::cout << junkpark << std::endl;
			Bureaucrat huipark("huipark", 1);
			std::cout << huipark << std::endl;
			Bureaucrat jimpark("jimpark",149);
			std::cout << jimpark << std::endl;
			Bureaucrat hyunjki("hyunjki", 151);
			std::cout << hyunjki << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "-----------------Form GradeToSign Low Test-----------------" << std::endl;
		try
		{
			Form a("a", 151, 1);
			std::cout << "실행 안됨" << std::endl;
		}
			catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "-----------------Form GradeToSign High Test-----------------" << std::endl;
		try
		{
			Form a("a", 0, 1);
			std::cout << "실행 안됨" << std::endl;
		}
			catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "-----------------Form GradeToExec Low Test-----------------" << std::endl;
		try
		{
			Form a("a", 1, 151);
			std::cout << "실행 안됨" << std::endl;
		}
			catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << "-----------------Form GradeToExec High Test-----------------" << std::endl;
		try
		{
			Form a("a",1, 0);
			std::cout << "실행 안됨" << std::endl;
		}
			catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}
