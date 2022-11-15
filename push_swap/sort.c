/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:57:39 by huipark           #+#    #+#             */
/*   Updated: 2022/11/15 20:15:09 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

static int	find_index(t_list *head, t_list *current)
{
	int	idx;
	t_list	*node;

	idx = 0;
	node = head;
	while (node->value != current->value)
	{
		node = node->next;
		idx++;
	}
	return (idx);
}

static void	separation2(t_point *A_info, t_point *B_info, t_arr_info *arr_info)
{
	t_list	*max_node;

	max_node = A_info->head->next;
	while (max_node->value != arr_info->max)
		max_node = max_node->next;
	max_node->index = find_index(A_info->head->next, max_node);
	while (A_info->head->size != 3)
	{
		if (A_info->tail->value == arr_info->max)
			ra(A_info);
		else
			pb(A_info, B_info);
	}
	if (A_info->head->next->next->value == arr_info->max)
		rra(A_info);
	else if (A_info->tail->value == arr_info->max)
		ra(A_info);
	if (A_info->tail->value > A_info->tail->prev->value)
		sa(A_info);
}

void	separation(t_point *A_info, t_point *B_info, t_arr_info *arr_info)
{
	while (A_info->head->size != A_info->head->start_size * 2 / 3)
	{
		if (A_info->tail->value <= arr_info->two_over_three_pivot)
			pb(A_info, B_info);
		else if (A_info->head->size != A_info->head->start_size * 2 / 3)
			ra(A_info);
	}
	while (A_info->head->size != A_info->head->start_size / 3)
	{
		if (A_info->tail->value <= arr_info->one_over_three_pivot)
			pb(A_info, B_info);
		else if (A_info->head->size != A_info->head->start_size / 3)
			ra(A_info);
	}
	separation2(A_info, B_info, arr_info);
}

int	a_upper (t_point *A_info, t_point *B_info, t_arr_info *arr_info, t_list *b)
{
	t_list	*a_bottom;
	int		command_count;
	int		idx;

	idx = b->index;
	a_bottom = A_info->head->next;
	command_count = 0;
	while (b->value < a_bottom->value && a_bottom->value != arr_info->max)
	{
		a_bottom = a_bottom->next;
		command_count++;
	}
	return (command_count);
}

int	command_min(t_point *A_info, t_point *B_info, t_arr_info *arr_info, t_list *current)
{
	t_list	*a_bottom = A_info->head->next;
	t_list	*a_top = A_info->tail;
	t_point *A = A_info;
	t_list	*b = current;
	int		command_count;
	int		value;

	value = b->value;
	command_count = 1;
	b->index = find_index(B_info->head->next, b);
	int idx = b->index;
	while (1)
	{
		if (A_info->tail->value > value)
		{
			if (value < a_bottom->value && a_bottom->value != arr_info->max)
				command_count = a_upper(A_info, B_info, arr_info, b);
			if (idx > list_size(B_info->head) / 2)
				b = b->next;
			else
			{
				if (B_info->head->next != b)
					b = b->prev;
				else
					b = B_info->tail;
			}
			command_count++;
		}
		else
		{
			while (a_top->value < value)
			{
				a_top = a_top->prev;
				command_count++;
			}
			if (idx > list_size(B_info->head) / 2 && b->next != NULL)
			{
				b = b->next;
				command_count++;
			}
			else if (idx <= list_size(B_info->head) / 2 && b->next != NULL)
			{
				if (B_info->head->next != b)
					b = b->prev;
				else
					b = B_info->tail;
				command_count++;
			}
			// command_count++;
		}
		if (b->next == NULL)
			break;
	}
	printf("command count = %d\n", command_count);
	return (command_count);
}

void	sort2(t_point *A_info, t_point *B_info, t_arr_info *arr_info)
{
	t_list	*temp;

	temp = B_info->head->next;
	while (temp)
	{
		printf("들어간 값  =   %d\n", temp->value);
		temp->command_min = command_min(A_info, B_info, arr_info, temp);
		temp = temp->next;
	}
}