#ifndef COMMAND_H
# define COMMAND_H

#include "data_struct.h"

void	sa(t_point *A_info);
void	sb(t_point *B_info);
void	ss(t_point *A_info, t_point *B_info);
void	pb(t_point *A_info, t_point *B_info);
void	pa(t_point *A_info, t_point *B_info);
void	ra(t_point *A_info);
void	rb(t_point *B_info);
void	rr(t_point *A_info, t_point *B_info);
void	rra(t_point *A_info);
void	rrb(t_point *B_info);
void	rrr(t_point *A_info, t_point *B_info);

#endif