/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_idu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:18:51 by huipark           #+#    #+#             */
/*   Updated: 2022/10/21 20:05:30 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	recursive(long long nbr, int count)
{
	int	tmp;

	if (nbr < 0)
	{
		if (nbr == -2147483648)
		{
			ft_putstr("-2147483648");
			return (11);
		}
		ft_putchar('-');
		nbr *= -1;
		count++;
	}
	if (nbr == 0 && count != 0)
		return (count);
	tmp = recursive(nbr / 10, count + 1);
	write (1, &"0123456789"[nbr % 10], 1);
	return (tmp);
}

int	ft_putnbr_id(int nbr)
{
	int	recursive_call;

	recursive_call = 0;
	recursive_call = recursive(nbr, recursive_call);
	return (recursive_call);
}

int	ft_putnbr_u(unsigned int nbr)
{
	int	recursive_call;

	recursive_call = 0;
	recursive_call = recursive(nbr, recursive_call);
	return (recursive_call);
}

