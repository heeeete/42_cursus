/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:38:53 by huipark           #+#    #+#             */
/*   Updated: 2022/11/17 22:04:48 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

void	go_ra(t_point *A_info, int rr_flag)
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
	if (!rr_flag)
		write (1, "ra\n", 3);
}

void	go_rb(t_point *B_info, int rr_flag)
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
	if (!rr_flag)
		write (1, "rb\n", 3);
}

// void	go_rr(t_point *A_info, t_point *B_info)
// {
// 	t_list	*head;
// 	t_list	*first_node;
// 	t_list	*tail_node;

// 	if (list_size((A_info)->head) > 1)
// 	{
// 		head = (A_info)->head;
// 		first_node = (A_info)->head->next;
// 		tail_node = (A_info)->tail->prev;
// 		(A_info)->head->next = (A_info)->tail;
// 		(A_info)->tail->prev = (A_info)->head;
// 		(A_info)->tail->next = first_node;
// 		first_node->prev = (A_info)->tail;
// 		tail_node->next = NULL;
// 		(A_info)->tail = tail_node;
// 	}
// 	if (list_size((B_info)->head) > 1)
// 	{
// 		head = (B_info)->head;
// 		first_node = (B_info)->head->next;
// 		tail_node = (B_info)->tail->prev;
// 		(B_info)->head->next = (B_info)->tail;
// 		(B_info)->tail->prev = (B_info)->head;
// 		(B_info)->tail->next = first_node;
// 		first_node->prev = (B_info)->tail;
// 		tail_node->next = NULL;
// 		(B_info)->tail = tail_node;
// 	}
// 	write (1, "rr\n", 3);
// }

void	go_rr(t_point *A_info, t_point *B_info)
{
	go_ra(A_info, 1);
	go_rb(B_info, 1);
	write (1, "rr\n", 3);
}