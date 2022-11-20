/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:57:39 by huipark           #+#    #+#             */
/*   Updated: 2022/11/20 19:22:43 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_list	*command_min_search(t_list	*node)
{
	int		command_count;
	int		command_count2;
	t_list	*temp;
	int		i;

	zero(&command_count2, &command_count, &i);
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
		zero(&command_count2, &command_count, &i);
	}
	return (temp);
}

// void	asd(t_point *A_info, t_point *B_info, t_list *node, char *command)
// {
// 	int	len;

// 	len = 0;
// 	while (command[len])
// 		len++;
// 	if (len == 2)
// 	{
// 		while (node->command[ra] != 0 && node->command[rb] != 0)
// 		{
// 			node->command[ra]--;
// 			node->command[rb]--;
// 			go_rr(A_info, B_info);
// 		}
// 	}
// 	else if (len == 3)
// 	{
// 		while (node->command[rra] != 0 && node->command[rrb] != 0)
// 		{
// 			node->command[rra]--;
// 			node->command[rrb]--;
// 			go_rrr(A_info, B_info);
// 		}
// 	}
// }

void	move(t_point *A_info, t_point *B_info, t_list *node)
{
	while (node->command[sa]-- != 0)
		go_sa(A_info);
	while (node->command[sb]-- != 0)
		go_sb(B_info);
	while (node->command[ss]-- != 0)
		go_ss(A_info, B_info);
	while (node->command[ra] != 0 && node->command[rb] != 0)
	{
		node->command[ra]--;
		node->command[rb]--;
		go_rr(A_info, B_info);
	}
	// asd(A_info, B_info, node, "rr");
	while (node->command[ra]-- != 0)
		go_ra(A_info, 0);
	while (node->command[rb]-- != 0)
		go_rb(B_info, 0);
	while (node->command[rra] != 0 && node->command[rrb] != 0)
	{
		node->command[rra]--;
		node->command[rrb]--;
		go_rrr(A_info, B_info);
	}
	// asd(A_info, B_info, node, "rrr");
	while (node->command[rra]-- != 0)
		go_rra(A_info, 0);
	while (node->command[rrb]-- != 0)
		go_rrb(B_info, 0);
	go_pa(A_info, B_info);
}

void	last_sort(t_point *A_info)
{
	int		max_node_idx;
	t_list	*max_node;

	max_node = A_info->head->next;
	while (max_node->value != A_info->head->max)
		max_node = max_node->next;
	max_node_idx = find_index(A_info->head->next, max_node);
	if (max_node_idx > A_info->head->start_size / 2)
		while (A_info->head->next->value != A_info->head->max)
			go_ra(A_info, 0);
	else
		while (A_info->head->next->value != A_info->head->max)
			go_rra(A_info, 0);
}

void	sort2(t_point *A_info, t_point *B_info, t_arr_info *arr_info)
{
	t_list	*temp;
	t_list	*asd;
	t_list	*q;

	A_info->head->max = arr_info->max;
	while (B_info->head->size != 0)
	{
		q = B_info->head->next;
		temp = B_info->head->next;
		while (temp)
		{
			init_arr(&temp->command);
			command_min(A_info, B_info, temp, &temp->command);
			temp = temp->next;
		}
		asd = command_min_search(B_info->head->next);
		move (A_info, B_info, asd);
		free (asd->command);
		while (q->next)
		{
			free(q->command);
			q = q->next;
		}
	}
	last_sort(A_info);
}
