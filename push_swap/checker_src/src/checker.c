/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:53:30 by huipark           #+#    #+#             */
/*   Updated: 2022/11/23 22:09:04 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	checker()
{

}

int main(int argc, char *argv[])
{
	t_point		*a_info;
	t_point		*b_info;
	t_arr_info	*arr_info;

	init_list(&a_info, &b_info, &arr_info);
	error_check(argc, argv);
	init_value(&a_info, argc, argv);
	error_check2(argc, a_info->head);
}