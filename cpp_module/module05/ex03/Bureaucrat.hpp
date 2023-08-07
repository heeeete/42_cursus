/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:54:41 by huipark           #+#    #+#             */
/*   Updated: 2023/08/01 15:48:05 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class AForm;

class Bureaucrat
{
private:
	const std::string name;
	int grade;
public:
	Bureaucrat();
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat& ref);
	~Bureaucrat();

	const std::string& getName() const;
	int getGrade() const;

	void signForm(AForm& form);

	Bureaucrat& operator=(const Bureaucrat& ref);

	std::range_error GradeTooHighException() const;
	std::range_error GradeTooLowException() const;
};

std::ostream& operator<<(std::ostream &temp, const Bureaucrat& ref);

#endif