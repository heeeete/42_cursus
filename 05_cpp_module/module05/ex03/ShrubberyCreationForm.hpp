/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:04:03 by huipark           #+#    #+#             */
/*   Updated: 2023/08/08 15:33:18 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	std::string _target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& src);
	~ShrubberyCreationForm();

	void execute(const Bureaucrat& executor) const;

	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& ref);
	class FileOpenError : public std::exception{
		virtual const char* what() const throw();
	};
};

#endif
