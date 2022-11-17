/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:45:57 by huipark           #+#    #+#             */
/*   Updated: 2022/11/17 21:48:25 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

void	go_sa(t_point *A_info)
{
	int	temp;

	if (list_size((A_info)->head) <= 1)
		return ;
	temp = (A_info)->tail->value;
	(A_info)->tail->value = (A_info)->tail->prev->value;
	(A_info)->tail->prev->value = temp;
	write (1, "sa\n", 3);
}

void	go_sb(t_point *B_info)
{
	int	temp;

	if (list_size((B_info)->head) <= 1)
		return ;
	temp = (B_info)->tail->value;
	(B_info)->tail->value = (B_info)->tail->prev->value;
	(B_info)->tail->prev->value = temp;
	write (1, "sb\n", 3);
}

void	go_ss(t_point *A_info, t_point *B_info)
{
	int	temp;

	if (list_size((A_info)->head) > 1)
	{
		temp = (A_info)->tail->value;
		(A_info)->tail->value = (A_info)->tail->prev->value;
		(A_info)->tail->prev->value = temp;
	}
	if (list_size((B_info)->head) > 1)
	{
		temp = (B_info)->tail->value;
		(B_info)->tail->value = (B_info)->tail->prev->value;
		(B_info)->tail->prev->value = temp;
	}
	write (1, "ss\n", 3);
}

void	go_pb(t_point *A_info, t_point *B_info)
{
	t_list *node;
	t_list *head;

	if (list_size((A_info)->head) == 0)
		return ;
	head = (B_info)->head;
	node = (A_info)->tail;
	while (head->next != NULL)
		head = head->next;
	(A_info)->tail->prev->next = NULL;
	(A_info)->tail = (A_info)->tail->prev;
	(B_info)->tail = node;
	head->next = node;
	node->next = NULL;
	node->prev = head;
	(B_info)->head->size += 1;
	(A_info)->head->size -= 1;
	write (1, "pb\n", 3);
}

void	go_pa(t_point *A_info, t_point *B_info)
{
	t_list *node;
	t_list *head;

	if (list_size((B_info)->head) == 0)
		return ;
	head = (A_info)->head;
	node = (B_info)->tail;
	while (head->next != NULL)
		head = head->next;
	(B_info)->tail->prev->next = NULL;
	(B_info)->tail = (B_info)->tail->prev;
	(A_info)->tail = node;
	head->next = node;
	node->next = NULL;
	node->prev = head;
	(B_info)->head->size -= 1;
	(A_info)->head->size += 1;
	write (1, "pa\n", 3);
}