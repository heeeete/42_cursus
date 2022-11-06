/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 20:53:48 by huipark           #+#    #+#             */
/*   Updated: 2022/11/06 17:00:47 by huipark          ###   ########.fr       */
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

long long int		ft_atoi(const char *str);
int		ERROR_check(int argc, char *argv[]);
int		ERROR_check2(t_list *head);
void	sa(t_point **A_info);
void	sb(t_point **B_info);
void	ss(t_point **A_info, t_point **B_info);
void	pb(t_point **A_info, t_point **B_info);
void	pa(t_point **A_info, t_point **B_info);
void	ra(t_point **A_info);
void	rb(t_point **B_info);
void	rr(t_point **A_info, t_point **B_info);
void	rra(t_point **A_info);
void	rrb(t_point **B_info);
void	rrr(t_point **A_info, t_point **B_info);
void	ft_putstr(char *s);
int		init_list(t_list **A, t_list **B, t_point **A_info , t_point **B_info);
int		list_size(t_list *head);
t_list	*newnode(t_list *head, char *argv);
t_list	*init_value(t_list **head, int argc, char *argv[]);
char	**ft_split(char const *s, char c);
void	ft_free(char **dest);



#endif