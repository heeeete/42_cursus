/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_struct_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:46:32 by huipark           #+#    #+#             */
/*   Updated: 2022/11/24 17:20:13 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_STRUCT_BONUS_H
# define DATA_STRUCT_BONUS_H

typedef struct s_list
{
	int				value;
	struct s_list	*prev;
	struct s_list	*next;
	int				size;
	int				index;
	int				max;
	int				a;
}	t_list;

typedef struct s_head_tail
{
	struct s_list	*head;
	struct s_list	*tail;
}	t_point;

#	endif
