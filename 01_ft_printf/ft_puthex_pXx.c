/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_pXx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:17:29 by huipark           #+#    #+#             */
/*   Updated: 2022/09/13 18:00:46 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	recursive(unsigned long long temp, int count)
{
	int	tmp;

	if (temp == 0 && count != 0)
		return (count);
	tmp = recursive(temp / 16, count + 1);
	write (1, &"0123456789abcdef"[temp % 16], 1);
	return (tmp);
}

static int	upper_recursive(unsigned long long temp, int count)
{
	int	tmp;

	if (temp == 0 && count != 0)
		return (count);
	tmp = upper_recursive(temp / 16, count + 1);
	write (1, &"0123456789ABCDEF"[temp % 16], 1);
	return (tmp);
}

int	ft_put_p(void *value)
{
	unsigned long long	temp;
	int					recursive_call;

	temp = (unsigned long long)value;
	recursive_call = 0;
	write(1, "0x", 2);
	recursive_call = recursive(temp, recursive_call);
	return (recursive_call + 2);
}

int	ft_put_x(unsigned int n, char c)
{
	int	recursive_call;

	recursive_call = 0;
	if (c == 'X')
		recursive_call = upper_recursive(n, recursive_call);
	else
		recursive_call = recursive(n, recursive_call);
	return (recursive_call);
}
