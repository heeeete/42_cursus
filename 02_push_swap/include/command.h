/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:35:06 by huipark           #+#    #+#             */
/*   Updated: 2022/11/20 19:35:12 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include "data_struct.h"

void	go_sa(t_point *a_info);
void	go_sb(t_point *b_info);
void	go_ss(t_point *a_info, t_point *b_info);
void	go_pb(t_point *a_info, t_point *b_info);
void	go_pa(t_point *a_info, t_point *b_info);
void	go_ra(t_point *a_info, int rr_flag);
void	go_rb(t_point *b_info, int rr_flag);
void	go_rr(t_point *a_info, t_point *b_info);
void	go_rra(t_point *a_info, int rrr_flag);
void	go_rrb(t_point *b_info, int rrr_flag);
void	go_rrr(t_point *a_info, t_point *b_info);

#endif