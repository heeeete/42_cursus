/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 20:53:48 by huipark           #+#    #+#             */
/*   Updated: 2022/11/16 21:16:48 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include "command.h"
#include "data_struct.h"

enum	command_name
{
	sa, sb, ss, ra, rb, rr, rra, rrb, rrr, pa, pb
};

long long int		ft_atoi(const char *str);
char				*ft_strdup(const char *s1);
void				init_list(t_point **A_info, t_point **B_info, t_arr_info **arr_info);
void				init_value(t_point **head, int argc, char *argv[]);
void				ft_free(char **dest);
void				newnode(t_list *head, char *str);
void				*wrap_malloc(size_t s);
void				error();
void				error_check(int argc, char *argv[]);
void				error_check2(int argc, t_list *head);
void				quicksort(int **arr, int start, int end);
void				separation(t_point *A_info, t_point *B_info, t_arr_info *arr_info);
void				sort2(t_point *A_info, t_point *B_info, t_arr_info *arr_info);
int					list_size(t_list *head);
char				**ft_split(char const *s, char c);
void	init_arr(int **arr);

#endif