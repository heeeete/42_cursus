/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:57:39 by huipark           #+#    #+#             */
/*   Updated: 2022/11/12 19:23:00 by huipark          ###   ########.fr       */
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

void	sort(t_point *A_info, t_point *B_info, t_arr_info *arr_info)
{
	while (B_info->head->size)
	{
		pa(&A_info, &B_info);
		if (&A_info->tail->value > &A_info->tail->prev->value)
			sa(&A_info);
	}
}