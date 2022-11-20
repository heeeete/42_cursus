/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ments.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:01:22 by huipark           #+#    #+#             */
/*   Updated: 2022/11/20 19:05:14 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_MENTS_H
# define MOVE_MENTS_H

# include "data_struct.h"

void	bottom_raise(t_point *A_info, t_list *b, int **command);
void	idx_up_down(t_point *B_info, t_list **b, int **cmd);
void	top_down(t_list *a_top, int **cmd, int value);
void	search_to_sb(t_point *B_info, t_list **current, int **cmd);
void	command_min(t_point *A_info, t_point *B_info,
			t_list *current, int **command);

#endif