/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:49:06 by huipark           #+#    #+#             */
/*   Updated: 2022/11/24 16:18:29 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <limits.h>
# include "command_bonus.h"
# include "data_struct_bonus.h"
# include "get_next_line.h"

enum	e_command_name
{
	sa,
	sb,
	ss,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr,
	pa,
	pb
};

long long int		ft_atoi(const char *str);
void				init_list(t_point **a_info, t_point **b_info);
void				init_value(t_point **head, int argc, char *argv[]);
int					find_index(t_list *head, t_list *current);
void				ft_free(char **dest);
void				newnode(t_list *head, char *str);
void				*wrap_malloc(size_t s);
void				error(void);
void				error_check(int argc, char *argv[]);
void				error_check2(int argc, t_list *head);
int					list_size(t_list *head);
char				**ft_split(char const *s, char c);
int					aligned_already(t_list *head);
int					ft_strcmp(const char *s1, const char *s2);
char				*get_next_line(int fd);
void				checker(t_point *a_info, t_point *b_info);

#endif