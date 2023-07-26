/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:54:26 by huipark           #+#    #+#             */
/*   Updated: 2023/07/26 21:22:48 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string _name;
	const int _gradeToSign;
	const int _gradeToExec;
	bool _signed;
public:
	Form();
	Form(const std::string name, int gradeToSign, int gradeToExec);
	Form(const Form& ref);
	~Form();

	const std::string& getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExec() const;
	

	Form& operator=(const Form& ref);

	std::range_error GradeTooHighException() const;
	std::range_error GradeTooLowException() const;
};

std::ostream& operator<<(std::ostream& temp, const Form& ref);

#endif
