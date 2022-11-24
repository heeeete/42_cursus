/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:59:10 by huipark           #+#    #+#             */
/*   Updated: 2022/11/24 19:57:49 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	bottom_raise(t_point *a_info, t_list *b, int *command)
{
	t_list	*a_bottom;
	int		command_count;
	int		idx;

	idx = b->index;
	a_bottom = a_info->head->next;
	command_count = 0;
	if (b->value < a_bottom->value && a_bottom->value != a_info->head->max)
	{
		while (b->value < a_bottom->value
			&& a_bottom->value != a_info->head->max)
		{
			a_bottom = a_bottom->next;
			(command)[rra]++;
		}
	}
}

static void	idx_up_down(t_point *b_info, t_list **b, int *cmd)
{
	int	idx;

	idx = (*b)->index;
	while ((*b)->next)
	{
		if (idx >= list_size(b_info->head) / 2 && (*b)->next != NULL)
		{
			*b = (*b)->next;
			cmd[rb]++;
		}
		else if (idx < list_size(b_info->head) / 2 && (*b)->next != NULL)
		{
			if (b_info->head->next != *b)
			{
				*b = (*b)->prev;
				cmd[rrb]++;
			}
			else
			{
				*b = b_info->tail;
				cmd[rrb]++;
			}
		}
	}
}

static void	top_down(t_list *a_top, int *cmd, int value)
{
	while (a_top->value < value)
	{
		a_top = a_top->prev;
		cmd[ra]++;
	}
}

static void	search_to_sb(t_point *b_info, t_list **current, int *cmd)
{
	if ((*current)->value == b_info->tail->prev->value)
	{
		cmd[sb]++;
		*current = b_info->tail;
	}
}

void	command_min(t_point *a_info, t_point *b_info,
						t_list *current, int *command)
{
	t_list	*a_bottom;
	t_list	*a_top;
	int		value;

	a_bottom = a_info->head->next;
	a_top = a_info->tail;
	value = current->value;
	current->index = find_index(b_info->head->next, current);
	if (a_info->tail->value > value)
	{
		bottom_raise(a_info, current, command);
		search_to_sb(b_info, &current, command);
	}
	else
		top_down(a_top, command, value);
	idx_up_down(b_info, &current, command);
	(command)[pa]++;
}
