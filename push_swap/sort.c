/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:57:39 by huipark           #+#    #+#             */
/*   Updated: 2022/11/17 23:35:35 by huipark          ###   ########.fr       */
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

void	a_upper (t_point *A_info, t_point *B_info, t_list *b, int **command)
{
	t_list	*a_bottom;
	int		command_count;
	int		idx;

	idx = b->index;
	a_bottom = A_info->head->next;
	command_count = 0;
	while (b->value < a_bottom->value && a_bottom->value != A_info->head->max)
	{
		a_bottom = a_bottom->next;
		(*command)[rra]++;
	}
}

void	idx_up_down(t_point *A_info, t_point *B_info, t_list **b, int **cmd)
{
	int idx;

	(*b)->index = find_index(B_info->head->next, *b);
	idx = (*b)->index;
	if (idx >= list_size(B_info->head) / 2 && (*b)->next != NULL)
	{
		*b = (*b)->next;
		(*cmd)[rb]++;
	}
	else if (idx < list_size(B_info->head) / 2 && (*b)->next != NULL)
	{
		if (B_info->head->next != *b)
		{
			*b = (*b)->prev;
			(*cmd)[rrb]++;
		}
		else
		{
			*b = B_info->tail;
			(*cmd)[rrb]++;
		}
	}
}

int	*command_min(t_point *A_info, t_point *B_info, t_list *current)
{
	t_list	*a_bottom = A_info->head->next;
	t_list	*a_top = A_info->tail;
	t_point *A = A_info;
	t_list	*b = current;
	int		command_count;
	int		value;
	int		*command;

	int		max_node_idx;
	t_list	*max_node;

	max_node = A_info->head->next;
	while (max_node->value != A_info->head->max)
		max_node = max_node->next;
	max_node_idx = find_index(A_info->head->next, max_node);

	init_arr(&command);
	value = b->value;
	command_count = 1;
	b->index = find_index(B_info->head->next, b);
	int idx = b->index;
	while (1)
	{
		if (A_info->tail->value > value)
		{
			if (max_node_idx > A_info->head->start_size / 2)
				while (a_top->value != max_node->prev->value)
				{
					a_top = a_top->prev;
					command[ra]++;
				}
			else if (value < a_bottom->value && a_bottom->value != A_info->head->max)
				a_upper(A_info, B_info, b, &command);
			if (value == B_info->tail->prev->value)
			{
				command[sb]++;
				b = B_info->tail;
			}
			else
				idx_up_down(A_info, B_info, &b, &command);
		}
		else
		{
			while (a_top->value < value)
			{
				a_top = a_top->prev;
				command[ra]++;
			}
			idx_up_down(A_info, B_info, &b, &command);
			// command_count++;
		}
		if (b->next == NULL)
			break;
	}
	command[pa]++;
	return (command);
}

void	zero(int *a, int *b, int *c)
{
	*a = 0;
	*b = 0;
	*c = 0;
}

t_list	*command_min_search(t_list	*node)
{
	int	command_count;
	int	command_count2;
	t_list	*temp;
	int	i;

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
	t_list						*temp;
	t_list	*asd;
	A_info->head->max = arr_info->max;
	t_list	*q;

	while (B_info->head->size != 0)
	{
		q = B_info->head->next;
		temp = B_info->head->next;
		while (temp)
		{
			temp->command = command_min(A_info, B_info, temp);
			temp = temp->next;
		}
		asd = command_min_search(B_info->head->next);
		// int i = 0;
		// while (i < 11)
		// 	printf("%d ", asd->command[i++]);
		// printf("\n");
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