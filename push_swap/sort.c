/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:57:39 by huipark           #+#    #+#             */
/*   Updated: 2022/11/14 22:47:26 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

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
	while (A_info->head->size != 3)
	{
		if (A_info->tail->value == arr_info->max)
			ra(A_info);
		else
			pb(A_info, B_info);
	}
	if (A_info->tail->value > A_info->tail->prev->value)
		sa(A_info);
}

int	find_index(t_list *head, t_list *current)
{
	int	idx;

	idx = 0;
	while (head->value != current->value)
	{
		head = head->next;
		idx++;
	}
	return (idx);
}

int	command_min(t_point *A_info, t_point *B_info, t_arr_info *arr_info, t_list *current)
{
	t_list	*a_bottom = A_info->head->next;
	t_list	*a_top = A_info->tail;
	t_list	*b = current;
	int		command_count;

	command_count = 1;
	b->index = find_index(B_info->head->next, b);
	while (b->next)
	{
		if (A_info->tail->value > b->value)
		{
			while (b->value < a_bottom->value && a_bottom->value != arr_info->max)
			{
				a_bottom = a_bottom->next;
				command_count++;
			}
			if (b->index > list_size(B_info->head) / 2)
			{
				// if (b->value != B_info->tail->value)
				// 	return (command_count);
				b = b->next;
				command_count++;
			}
			else
			{
				if (b->value == B_info->head->next->value)
					return (command_count + 1);
				if (B_info->head->next->value != b->value)
				{
					printf("%d    %d\n", B_info->head->next->value, b->value);
					b = b->prev;
				}
				else
					b = B_info->tail;
				command_count++;
			}
		}
		else
		{
			while (a_top->value < b->value)
			{
				// printf("AA\n");
				a_top = a_top->prev;
				command_count++;
			}
			if (b->index > list_size(B_info->head) / 2)
			{
				// if (b->value == B_info->tail->value)
				// 	return (command_count);
				b = b->next;
				command_count++;
			}
			else
			{
				if (b->value == B_info->head->next->value)
					return (command_count + 1);
				if (B_info->head->next->value != b->value)
					b = b->prev;
				else
					b = B_info->tail;
				command_count++;
			}
		}
	}
	return (command_count);
}

void	sort2(t_point *A_info, t_point *B_info, t_arr_info *arr_info)
{
	t_list	*temp;

	temp = B_info->head->next;
	while (temp)
	{
		temp->command_min = command_min(A_info, B_info, arr_info, temp);
		temp = temp->next;
	}
}