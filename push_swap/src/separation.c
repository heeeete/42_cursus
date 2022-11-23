/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:40:42 by huipark           #+#    #+#             */
/*   Updated: 2022/11/23 21:38:53 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	the_rest_sorting(t_point *a_info, t_point *b_info)
{
	while (b_info->head->size != 0)
	{
		while (b_info->tail->value < a_info->head->next->value
			&& a_info->head->next->value != a_info->head->max
			&& a_info->head->next->value < a_info->tail->value)
			go_rra(a_info, 0);
		while (b_info->tail->value > a_info->tail->value)
			go_ra(a_info, 0);
		go_pa(a_info, b_info);
	}
	while (a_info->head->next->value != a_info->head->max)
		go_rra(a_info, 0);
}

static void	three_size_stack_sort(t_point *a_info)
{
	if (a_info->head->next->next->value == a_info->head->max)
		go_rra(a_info, 0);
	else if (a_info->tail->value == a_info->head->max)
		go_ra(a_info, 0);
	if (a_info->head->next->next->value < a_info->tail->value)
		go_sa(a_info);
}

static void	small_stack(t_point *a_info, t_point *b_info)
{
	if (list_size(a_info->head) == 2 && a_info->head->next < a_info->tail)
		go_sa(a_info);
	else if (list_size(a_info->head) == 3)
		three_size_stack_sort(a_info);
	else if (list_size(a_info->head) == 5 || list_size(a_info->head) == 4)
	{
		while (list_size(a_info->head) != 3)
		{
			if (a_info->tail->value == a_info->head->max)
				go_ra(a_info, 0);
			else
				go_pb(a_info, b_info);
		}
		three_size_stack_sort(a_info);
		the_rest_sorting(a_info, b_info);
	}
	exit(0);
}

static void	separation2(t_point *a_info, t_point *b_info, t_arr_info *arr_info)
{
	while (a_info->head->size > 2)
	{
		if (a_info->tail->value == arr_info->max)
			go_ra(a_info, 0);
		else
			go_pb(a_info, b_info);
	}
	if (list_size(a_info->head) > 2
		&& a_info->head->next->next->value == arr_info->max)
		go_rra(a_info, 0);
	else if (a_info->tail->value == arr_info->max)
		go_ra(a_info, 0);
	if (a_info->tail->value > a_info->tail->prev->value)
		go_sa(a_info);
}

void	separation(t_point *a_info, t_point *b_info, t_arr_info *arr_info)
{
	if (list_size(a_info->head) <= 5)
		small_stack(a_info, b_info);
	while (a_info->head->size != a_info->head->start_size / 3)
	{
		if (a_info->tail->value <= arr_info->two_over_three_pivot)
			go_pb(a_info, b_info);
		else if (a_info->tail->value <= arr_info->one_over_three_pivot)
		{
			go_pb(a_info, b_info);
			go_rb(b_info, 0);
		}
		else
			go_ra(a_info, 0);
	}
	separation2(a_info, b_info, arr_info);
}
