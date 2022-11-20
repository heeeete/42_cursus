/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:38:53 by huipark           #+#    #+#             */
/*   Updated: 2022/11/20 19:33:47 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	go_ra(t_point *a_info, int rr_flag)
{
	t_list	*first_node;
	t_list	*tail_node;

	if (list_size((a_info)->head) <= 1)
		return ;
	first_node = (a_info)->head->next;
	tail_node = (a_info)->tail->prev;
	(a_info)->head->next = (a_info)->tail;
	(a_info)->tail->prev = (a_info)->head;
	(a_info)->tail->next = first_node;
	first_node->prev = (a_info)->tail;
	tail_node->next = NULL;
	(a_info)->tail = tail_node;
	if (!rr_flag)
		write (1, "ra\n", 3);
}

void	go_rb(t_point *b_info, int rr_flag)
{
	t_list	*first_node;
	t_list	*tail_node;

	if (list_size((b_info)->head) <= 1)
		return ;
	first_node = (b_info)->head->next;
	tail_node = (b_info)->tail->prev;
	(b_info)->head->next = (b_info)->tail;
	(b_info)->tail->prev = (b_info)->head;
	(b_info)->tail->next = first_node;
	first_node->prev = (b_info)->tail;
	tail_node->next = NULL;
	(b_info)->tail = tail_node;
	if (!rr_flag)
		write (1, "rb\n", 3);
}

void	go_rr(t_point *a_info, t_point *b_info)
{
	go_ra(a_info, 1);
	go_rb(b_info, 1);
	write (1, "rr\n", 3);
}
