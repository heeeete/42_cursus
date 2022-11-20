/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:40:42 by huipark           #+#    #+#             */
/*   Updated: 2022/11/20 19:34:48 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	if (list_size(a_info->head) == 2)
	{
		if (a_info->head->next < a_info->tail)
			go_sa(a_info);
		exit(0);
	}
	while (a_info->head->size != a_info->head->start_size * 2 / 3)
	{
		if (a_info->tail->value <= arr_info->two_over_three_pivot)
			go_pb(a_info, b_info);
		else if (a_info->head->size != a_info->head->start_size * 2 / 3)
			go_ra(a_info, 0);
	}
	while (a_info->head->size != a_info->head->start_size / 3)
	{
		if (a_info->tail->value <= arr_info->one_over_three_pivot)
			go_pb(a_info, b_info);
		else if (a_info->head->size != a_info->head->start_size / 3)
			go_ra(a_info, 0);
	}
	separation2(a_info, b_info, arr_info);
}
