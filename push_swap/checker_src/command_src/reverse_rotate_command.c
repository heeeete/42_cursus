/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:31:56 by huipark           #+#    #+#             */
/*   Updated: 2022/11/23 21:59:15 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	go_rra(t_point *a_info)
{
	t_list	*first_node;
	t_list	*second_node;

	if (list_size((a_info)->head) <= 1)
		return ;
	first_node = (a_info)->head->next;
	second_node = first_node->next;
	(a_info)->tail->next = first_node;
	first_node->prev = (a_info)->tail;
	(a_info)->head->next = second_node;
	second_node->prev = (a_info)->head;
	first_node->next = NULL;
	(a_info)->tail = first_node;
}

void	go_rrb(t_point *b_info)
{
	t_list	*first_node;
	t_list	*second_node;

	if (list_size((b_info)->head) <= 1)
		return ;
	first_node = (b_info)->head->next;
	second_node = first_node->next;
	(b_info)->tail->next = first_node;
	first_node->prev = (b_info)->tail;
	(b_info)->head->next = second_node;
	second_node->prev = (b_info)->head;
	first_node->next = NULL;
	(b_info)->tail = first_node;
}

void	go_rrr(t_point *a_info, t_point *b_info)
{
	go_rra(a_info, 1);
	go_rrb(b_info, 1);
}
