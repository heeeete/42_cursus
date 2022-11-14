/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:57:39 by huipark           #+#    #+#             */
/*   Updated: 2022/11/13 19:48:01 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

void	separation(t_point *A_info, t_point *B_info, t_arr_info *arr_info)
{
	while (A_info->head->size != A_info->head->start_size * 2 / 3)
	{
		if (A_info->tail->value <= arr_info->two_over_three_pivot)
			pb(&A_info, &B_info);
		else if (A_info->head->size != A_info->head->start_size * 2 / 3)
			ra(&A_info);
	}
	while (A_info->head->size != A_info->head->start_size / 3)
	{
		if (A_info->tail->value <= arr_info->one_over_three_pivot)
			pb(&A_info, &B_info);
		else if (A_info->head->size != A_info->head->start_size / 3)
			ra(&A_info);
	}
	while (A_info->head->size != 3)
	{
		if (A_info->tail->value == arr_info->max)
			ra(&A_info);
		else
			pb(&A_info, &B_info);
	}
	if (A_info->tail->value > A_info->tail->prev->value)
		sa(&A_info);
}

// int	get_min_command(t_point *A_info, t_point *B_info, t_arr_info *arr_info)
// {

// }

t_list	*search_max_node(t_point *B_info)
{
	t_list	*node;
	t_list	*b_stack;
	int		idx;

	idx = 1;
	b_stack = B_info->head->next;
	node = b_stack;
	while (b_stack->next)
	{
		if (node->value < b_stack->next->value)
			node = b_stack->next;
		b_stack = b_stack->next;
		idx++;
	}
	node->index = idx;
	return (node);
}

int	temp_sort(t_point *A_info, t_point *B_info, t_arr_info *arr_info)
{
	t_point	*node = B_info;
	t_point *A = A_info;
	t_point *B = B_info;
	while (list_size(node->head) != 0)
		pa(&A_info, &node);
	A_info = A;
	B_info = B;
	
}

// int	min_command(t_point *A_info, t_point *B_info, t_arr_info *arr_info)
// {
// 	t_list	*node = B_info->head->next;
// 	while (node->next)
// 	{
// 		node
// 	}
// }

void	sort2(t_point *A_info, t_point *B_info, t_arr_info *arr_info)
{
	temp_sort(A_info, B_info, arr_info);
	// while (B_info->head->size != 0)
	// {
	// }
}