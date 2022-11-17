#ifndef COMMAND_H
# define COMMAND_H

#include "data_struct.h"

void	go_sa(t_point *A_info);
void	go_sb(t_point *B_info);
void	go_ss(t_point *A_info, t_point *B_info);
void	go_pb(t_point *A_info, t_point *B_info);
void	go_pa(t_point *A_info, t_point *B_info);
void	go_ra(t_point *A_info, int rr_flag);
void	go_rb(t_point *B_info, int rr_flag);
void	go_rr(t_point *A_info, t_point *B_info);
void	go_rra(t_point *A_info, int rrr_flag);
void	go_rrb(t_point *B_info, int rrr_flag);
void	go_rrr(t_point *A_info, t_point *B_info);

#endif