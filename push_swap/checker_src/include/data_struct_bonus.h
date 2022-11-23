/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:40:10 by huipark           #+#    #+#             */
/*   Updated: 2022/11/24 01:20:02 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_STRUCT_H
# define DATA_STRUCT_H

typedef struct s_list
{
	int				value;
	struct s_list	*prev;
	struct s_list	*next;
	int				size;
	int				start_size;
	int				index;
	int				*command;
	int				max;
}	t_list;

typedef struct s_head_tail
{
	struct s_list	*head;
	struct s_list	*tail;
}	t_point;

typedef struct s_arr_info
{
	int	*arr;
	int	max;
	int	min;
	int	one_over_three_pivot;
	int	two_over_three_pivot;
}	t_arr_info;

#	endif
