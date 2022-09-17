/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:18:54 by huipark           #+#    #+#             */
/*   Updated: 2022/09/17 16:57:06 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putnbr_id(int nbr);
int	ft_putnbr_u(unsigned int nbr);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_put_p(void *value);
int	ft_put_x(unsigned int n, char c);
int	ft_printf(const char *format, ...);

#endif