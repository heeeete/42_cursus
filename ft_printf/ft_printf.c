/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:18:17 by huipark           #+#    #+#             */
/*   Updated: 2022/09/12 21:57:18 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_check(char c, va_list *ap)
{
	if (c == 'd' || c == 'i')
		return (ft_putnbr_id(va_arg(*ap, int)));
	else if (c == 'u')
		return (ft_putnbr_u(va_arg(*ap, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*ap, char *)));
	else if (c == 'c')
		return (ft_putchar(va_arg(*ap, int)));
	else if (c == 'p')
		return (ft_put_p(va_arg(*ap, void *)));
	else if (c == 'X' || c == 'x')
		return (ft_put_Xx(va_arg(*ap, unsigned int), c));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		read_count;

	va_start (ap, format);
	read_count = 0;
	while (*format)
	{
		if (*format == '%')
			read_count = format_check(*++format, &ap);
		else
			write (1, format, 1);
		format++;
	}
	return (read_count);
}

int main()
{
	printf("%X\n", 2147483647);
	ft_printf("%X", 2147483647);
}
