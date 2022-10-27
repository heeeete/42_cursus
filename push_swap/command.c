/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:45:57 by huipark           #+#    #+#             */
/*   Updated: 2022/10/27 20:23:55 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack_A, t_list *A_head)
{
	int	temp;

	if (list_size(A_head) == 1)
		return ;
	temp = (*stack_A)->value;
	(*stack_A)->value = (*stack_A)->prev->value;
	(*stack_A)->prev->value = temp;
}

void	sb(t_list **stack_B, t_list *B_head)
{
	int	temp;

	if (list_size(B_head) == 1)
		return ;
	temp = (*stack_B)->value;
	(*stack_B)->value = (*stack_B)->prev->value;
	(*stack_B)->prev->value = temp;
}