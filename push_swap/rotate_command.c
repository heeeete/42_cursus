/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:38:53 by huipark           #+#    #+#             */
/*   Updated: 2022/11/14 16:39:54 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

void	ra(t_point *A_info)
{
	t_list	*first_node;
	t_list	*tail_node;

	if (list_size((A_info)->head) <= 1)
		return ;
	first_node = (A_info)->head->next;
	tail_node = (A_info)->tail->prev;
	(A_info)->head->next = (A_info)->tail;
	(A_info)->tail->prev = (A_info)->head;
	(A_info)->tail->next = first_node;
	first_node->prev = (A_info)->tail;
	tail_node->next = NULL;
	(A_info)->tail = tail_node;
	write (1, "ra\n", 3);
}

void	rb(t_point *B_info)
{
	t_list	*first_node;
	t_list	*tail_node;

	if (list_size((B_info)->head) <= 1)
		return ;
	first_node = (B_info)->head->next;
	tail_node = (B_info)->tail->prev;
	(B_info)->head->next = (B_info)->tail;
	(B_info)->tail->prev = (B_info)->head;
	(B_info)->tail->next = first_node;
	first_node->prev = (B_info)->tail;
	tail_node->next = NULL;
	(B_info)->tail = tail_node;
	write (1, "rb\n", 3);
}

void	rr(t_point *A_info, t_point *B_info)
{
	t_list	*head;
	t_list	*first_node;
	t_list	*tail_node;

	if (list_size((A_info)->head) > 1)
	{
		head = (A_info)->head;
		first_node = (A_info)->head->next;
		tail_node = (A_info)->tail->prev;
		(A_info)->head->next = (A_info)->tail;
		(A_info)->tail->prev = (A_info)->head;
		(A_info)->tail->next = first_node;
		first_node->prev = (A_info)->tail;
		tail_node->next = NULL;
		(A_info)->tail = tail_node;
	}
	if (list_size((B_info)->head) > 1)
	{
		head = (B_info)->head;
		first_node = (B_info)->head->next;
		tail_node = (B_info)->tail->prev;
		(B_info)->head->next = (B_info)->tail;
		(B_info)->tail->prev = (B_info)->head;
		(B_info)->tail->next = first_node;
		first_node->prev = (B_info)->tail;
		tail_node->next = NULL;
		(B_info)->tail = tail_node;
	}
	write (1, "rr\n", 3);
}