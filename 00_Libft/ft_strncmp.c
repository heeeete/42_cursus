/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 01:43:08 by huipark           #+#    #+#             */
/*   Updated: 2022/08/03 01:34:19 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 || *s2) && n > 0)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
			n--;
		}
		else
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
	}
	return (0);
}
