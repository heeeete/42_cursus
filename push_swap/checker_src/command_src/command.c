/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:45:57 by huipark           #+#    #+#             */
/*   Updated: 2022/11/23 21:59:23 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	go_sa(t_point *a_info)
{
	int	temp;

	if (list_size((a_info)->head) <= 1)
		return ;
	temp = (a_info)->tail->value;
	(a_info)->tail->value = (a_info)->tail->prev->value;
	(a_info)->tail->prev->value = temp;
}

void	go_sb(t_point *b_info)
{
	int	temp;

	if (list_size((b_info)->head) <= 1)
		return ;
	temp = (b_info)->tail->value;
	(b_info)->tail->value = (b_info)->tail->prev->value;
	(b_info)->tail->prev->value = temp;
}

void	go_ss(t_point *a_info, t_point *b_info)
{
	int	temp;

	if (list_size((a_info)->head) > 1)
	{
		temp = (a_info)->tail->value;
		(a_info)->tail->value = (a_info)->tail->prev->value;
		(a_info)->tail->prev->value = temp;
	}
	if (list_size((b_info)->head) > 1)
	{
		temp = (b_info)->tail->value;
		(b_info)->tail->value = (b_info)->tail->prev->value;
		(b_info)->tail->prev->value = temp;
	}
}

void	go_pb(t_point *a_info, t_point *b_info)
{
	t_list	*node;
	t_list	*head;

	if (list_size((a_info)->head) == 0)
		return ;
	head = (b_info)->head;
	node = (a_info)->tail;
	while (head->next != NULL)
		head = head->next;
	(a_info)->tail->prev->next = NULL;
	(a_info)->tail = (a_info)->tail->prev;
	(b_info)->tail = node;
	head->next = node;
	node->next = NULL;
	node->prev = head;
	(b_info)->head->size += 1;
	(a_info)->head->size -= 1;
	write (1, "pb\n", 3);
}

void	go_pa(t_point *a_info, t_point *b_info)
{
	t_list	*node;
	t_list	*head;

	if (list_size((b_info)->head) == 0)
		return ;
	head = (a_info)->head;
	node = (b_info)->tail;
	while (head->next != NULL)
		head = head->next;
	(b_info)->tail->prev->next = NULL;
	(b_info)->tail = (b_info)->tail->prev;
	(a_info)->tail = node;
	head->next = node;
	node->next = NULL;
	node->prev = head;
	(b_info)->head->size -= 1;
	(a_info)->head->size += 1;
}
