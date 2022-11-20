/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:31:56 by huipark           #+#    #+#             */
/*   Updated: 2022/11/20 16:36:55 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	go_rra(t_point *A_info, int rrr_flag)
{
	t_list	*first_node;
	t_list	*second_node;

	if (list_size((A_info)->head) <= 1)
		return ;
	first_node = (A_info)->head->next;
	second_node = first_node->next;
	(A_info)->tail->next = first_node;
	first_node->prev = (A_info)->tail;
	(A_info)->head->next = second_node;
	second_node->prev = (A_info)->head;
	first_node->next = NULL;
	(A_info)->tail = first_node;
	if (!rrr_flag)
		write (1, "rra\n", 4);
}

void	go_rrb(t_point *B_info, int rrr_flag)
{
	t_list	*first_node;
	t_list	*second_node;

	if (list_size((B_info)->head) <= 1)
		return ;
	first_node = (B_info)->head->next;
	second_node = first_node->next;
	(B_info)->tail->next = first_node;
	first_node->prev = (B_info)->tail;
	(B_info)->head->next = second_node;
	second_node->prev = (B_info)->head;
	first_node->next = NULL;
	(B_info)->tail = first_node;
	if (!rrr_flag)
		write (1, "rrb\n", 4);
}

void	go_rrr(t_point *A_info, t_point *B_info)
{
	go_rra(A_info, 1);
	go_rrb(B_info, 1);
	write (1, "rrr\n", 4);
}
