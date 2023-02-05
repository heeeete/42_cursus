/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:50:51 by huipark           #+#    #+#             */
/*   Updated: 2023/02/04 17:51:54 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

int	print_err(int error_code)
{
	static const char	*msg[] =
	{
		NULL,
		"Error: Arguments has 5 or 6",
		"Error: Arguments can only be number",
		"Error: malloc fail",
		"Error: mutex fail",
		"Error: run time fail",
	};
	printf("%s\n", msg[error_code]);
	return (FAILURE);
}
