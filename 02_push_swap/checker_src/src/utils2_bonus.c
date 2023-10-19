/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:52:58 by huipark           #+#    #+#             */
/*   Updated: 2022/11/24 16:58:34 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"
#include <unistd.h>

int	aligned_already(t_list *head)
{
	while (head->next)
	{
		if (head->value > head->next->value)
			head = head->next;
		else
			return (0);
	}
	return (1);
}

void	checker(t_point *a_info, t_point *b_info)
{
	if (b_info->head->size == 0 && aligned_already(a_info->head->next))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	init_zero(int *a, int *b, int *c)
{
	*a = 0;
	*b = 0;
	*c = 0;
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
		else
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
	}
	return (0);
}
