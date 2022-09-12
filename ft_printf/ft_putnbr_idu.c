/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_idu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:18:51 by huipark           #+#    #+#             */
/*   Updated: 2022/09/12 19:07:43 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_id(int nbr)
{
	if (nbr / 10 != 0)
		ft_putnbr_id(nbr / 10);
	write (1, &"0123456789"[nbr % 10], 1);
	return (1);
}

int	ft_putnbr_u(unsigned int nbr)
{
	if (nbr / 10 != 0)
		ft_putnbr_u(nbr / 10);
	write (1, &"0123456789"[nbr % 10], 1);
	return (1);
}
