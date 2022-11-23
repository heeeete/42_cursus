/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:52:58 by huipark           #+#    #+#             */
/*   Updated: 2022/11/23 22:03:34 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	aligned_already(t_list *head)
{
	while (head->next)
	{
		if (head->value > head->next->value)
			head = head->next;
		else
			return ;
	}
	exit(0);
}

void	init_zero(int *a, int *b, int *c)
{
	*a = 0;
	*b = 0;
	*c = 0;
}
