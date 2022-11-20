/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:40:42 by huipark           #+#    #+#             */
/*   Updated: 2022/11/20 16:21:12 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	separation2(t_point *A_info, t_point *B_info, t_arr_info *arr_info)
{
	while (A_info->head->size > 2)
	{
		if (A_info->tail->value == arr_info->max)
			go_ra(A_info, 0);
		else
			go_pb(A_info, B_info);
	}
	if (list_size(A_info->head) > 2 && A_info->head->next->next->value == arr_info->max)
		go_rra(A_info, 0);
	else if (A_info->tail->value == arr_info->max)
		go_ra(A_info, 0);
	if (A_info->tail->value > A_info->tail->prev->value)
		go_sa(A_info);
}

void	separation(t_point *A_info, t_point *B_info, t_arr_info *arr_info)
{
	if (list_size(A_info->head) == 2)
	{
		if (A_info->head->next < A_info->tail)
			go_sa(A_info);
		exit(0);
	}
	while (A_info->head->size != A_info->head->start_size * 2 / 3)
	{
		// printf("A_info -> size  = %d\n start -> size = %d\n", A_info->head->size, A_info->head->start_size * 2 / 3);
		if (A_info->tail->value <= arr_info->two_over_three_pivot)
			go_pb(A_info, B_info);
		else if (A_info->head->size != A_info->head->start_size * 2 / 3)
			go_ra(A_info, 0);
	}
	while (A_info->head->size != A_info->head->start_size / 3)
	{
		if (A_info->tail->value <= arr_info->one_over_three_pivot)
			go_pb(A_info, B_info);
		else if (A_info->head->size != A_info->head->start_size / 3)
			go_ra(A_info, 0);
	}
	separation2(A_info, B_info, arr_info);
}