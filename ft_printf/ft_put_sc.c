/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_sc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:11:31 by huipark           #+#    #+#             */
/*   Updated: 2022/09/12 21:51:47 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	if (!str)
		return (0);
	while (*str)
		write(1, str++, 1);
	return (1);
}

int ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}