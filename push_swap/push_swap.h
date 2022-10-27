/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 20:53:48 by huipark           #+#    #+#             */
/*   Updated: 2022/10/27 20:24:06 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

typedef struct s_list
{
	int				value;
	struct s_list	*prev;
	struct s_list	*next;
	int				size;
}	t_list;

typedef struct s_head_tail
{
	struct s_list	*head;
	struct s_list	*tail;
}	t_point;

int		ft_atoi(const char *str);
int		ERROR_check(int argc, char *argv[]);
int		ERROR_check2(int argc, char *argv[]);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putstr(char *s);
void	sa(t_list **stack_A, t_list *A_head);
void	sb(t_list **stack_B, t_list *B_head);
int		list_size(t_list *head);

#endif