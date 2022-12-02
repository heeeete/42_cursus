/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:53:30 by huipark           #+#    #+#             */
/*   Updated: 2022/11/28 17:15:15 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../include/checker.h"

void	sort(t_point *a_info, t_point *b_info, char *str)
{
	if (!(ft_strcmp("sa\n", str)))
		go_sa(a_info);
	else if (!(ft_strcmp("sb\n", str)))
		go_sb(b_info);
	else if (!(ft_strcmp("ss\n", str)))
		go_ss(a_info, b_info);
	else if (!(ft_strcmp("rr\n", str)))
		go_rr(a_info, b_info);
	else if (!(ft_strcmp("ra\n", str)))
		go_ra(a_info);
	else if (!(ft_strcmp("rb\n", str)))
		go_rb(b_info);
	else if (!(ft_strcmp("rrr\n", str)))
		go_rrr(a_info, b_info);
	else if (!(ft_strcmp("rra\n", str)))
		go_rra(a_info);
	else if (!(ft_strcmp("rrb\n", str)))
		go_rrb(b_info);
	else if (!(ft_strcmp("pa\n", str)))
		go_pa(a_info, b_info);
	else if (!(ft_strcmp("pb\n", str)))
		go_pb(a_info, b_info);
	else
		error();
}

void	take_input(t_point *a_info, t_point *b_info)
{
	char	*str;

	while (1)
	{
		str = get_next_line(STDIN_FILENO);
		if (!str)
			break ;
		sort(a_info, b_info, str);
		free (str);
	}
}

int	main(int argc, char *argv[])
{
	t_point		*a_info;
	t_point		*b_info;

	init_list(&a_info, &b_info);
	error_check(argc, argv);
	init_value(&a_info, argc, argv);
	error_check2(argc, a_info->head);
	take_input(a_info, b_info);
	checker(a_info, b_info);
}
