/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:00:42 by huipark           #+#    #+#             */
/*   Updated: 2022/11/20 23:09:49 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char *argv[])
{
	t_point		*a_info;
	t_point		*b_info;
	t_arr_info	*arr_info;

	init_list(&a_info, &b_info, &arr_info);
	error_check(argc, argv);
	init_value(&a_info, argc, argv);
	aligned_already(a_info->head->next);
	error_check2(argc, a_info->head);
	set_arr(&arr_info, argv);
	separation(a_info, b_info, arr_info);
	sort2(a_info, b_info, arr_info);
}
