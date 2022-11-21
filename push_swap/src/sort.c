/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:57:39 by huipark           #+#    #+#             */
/*   Updated: 2022/11/21 17:51:27 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_list	*command_min_search(t_list	*node)
{
	int		command_count;
	int		command_count2;
	t_list	*temp;
	int		i;

	init_zero(&command_count2, &command_count, &i);
	temp = node;
	if (node->next != NULL)
		node = node->next;
	while (node)
	{
		while (i < 11)
		{
			command_count += node->command[i];
			command_count2 += temp->command[i++];
		}
		if (command_count2 > command_count)
			temp = node;
		else if (command_count2 == command_count)
			if (temp->value < node->value)
				temp = node;
		node = node->next;
		init_zero(&command_count2, &command_count, &i);
	}
	return (temp);
}

static void	rotate(t_point *a_info, t_point *b_info,
			t_list *node, char *command)
{
	int	len;

	len = 0;
	while (command[len])
		len++;
	if (len == 2)
	{
		while (node->command[ra] != 0 && node->command[rb] != 0)
		{
			node->command[ra]--;
			node->command[rb]--;
			go_rr(a_info, b_info);
		}
	}
	else if (len == 3)
	{
		while (node->command[rra] != 0 && node->command[rrb] != 0)
		{
			node->command[rra]--;
			node->command[rrb]--;
			go_rrr(a_info, b_info);
		}
	}
}

static void	move(t_point *a_info, t_point *b_info, t_list *node)
{
	while (node->command[sa]-- != 0)
		go_sa(a_info);
	while (node->command[sb]-- != 0)
		go_sb(b_info);
	while (node->command[ss]-- != 0)
		go_ss(a_info, b_info);
	rotate(a_info, b_info, node, "rr");
	while (node->command[ra]-- != 0)
		go_ra(a_info, 0);
	while (node->command[rb]-- != 0)
		go_rb(b_info, 0);
	rotate(a_info, b_info, node, "rrr");
	while (node->command[rra]-- != 0)
		go_rra(a_info, 0);
	while (node->command[rrb]-- != 0)
		go_rrb(b_info, 0);
	go_pa(a_info, b_info);
}

static void	last_sort(t_point *a_info)
{
	int		max_node_idx;
	t_list	*max_node;

	max_node = a_info->head->next;
	while (max_node->value != a_info->head->max)
		max_node = max_node->next;
	max_node_idx = find_index(a_info->head->next, max_node);
	if (max_node_idx > a_info->head->start_size / 2)
		while (a_info->head->next->value != a_info->head->max)
			go_ra(a_info, 0);
	else
		while (a_info->head->next->value != a_info->head->max)
			go_rra(a_info, 0);
}

void	sort2(t_point *a_info, t_point *b_info)
{
	t_list	*current;
	t_list	*cmd_min_node;
	t_list	*temp;

	while (b_info->head->size != 0)
	{
		temp = b_info->head->next;
		current = b_info->head->next;
		while (current)
		{
			init_arr(&current->command);
			command_min(a_info, b_info, current, &current->command);
			current = current->next;
		}
		cmd_min_node = command_min_search(b_info->head->next);
		move (a_info, b_info, cmd_min_node);
		while (temp)
		{
			free(temp->command);
			temp = temp->next;
		}
	}
	last_sort(a_info);
}
