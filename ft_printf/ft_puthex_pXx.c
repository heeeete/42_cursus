/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_pXx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:17:29 by huipark           #+#    #+#             */
/*   Updated: 2022/09/12 21:57:36 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	recursive(unsigned long long temp)
{
	if (temp / 16 != 0)
		recursive(temp / 16);
	write (1, &"0123456789abcdef"[temp % 16], 1);
	return (0);
}

int	RECURSIVE(unsigned long long temp)
{
	if (temp / 16 != 0)
		RECURSIVE(temp / 16);
	write (1, &"0123456789ABCDEF"[temp % 16], 1);
	return (0);
}

int	ft_put_p(void *value)
{
	unsigned long long temp;

	temp = (unsigned long long)value;
	write(1, "0x", 2);
	recursive(temp);
	return (1);
}

int ft_put_Xx(unsigned int n, char c)
{
	if (c == 'X')
		RECURSIVE(n);
	else
		recursive(n);
	return (0);
}