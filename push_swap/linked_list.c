/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:37:14 by huipark           #+#    #+#             */
/*   Updated: 2022/11/16 18:25:17 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

int	list_size(t_list *head)
{
	int size;

	size = 0;
	while (head->next != NULL)
	{
		head = head->next;
		size++;
	}
	return (size);
}

void	newnode(t_list *head, char *str)
{
	t_list	*newnode;

	while (head->next != NULL)
		head = head->next;
	newnode = wrap_malloc(sizeof(t_list));
	newnode->value = ft_atoi(str);
	newnode->next = NULL;
	newnode->prev = head;
	head->next = newnode;
}

void	init_value(t_point **info, int argc, char *argv[])
{
	t_list	*node;
	char	**str;
	int		i;

	i = 0;
	node = (*info)->tail;
	while (argc != 1)
	{
		str = ft_split(argv[argc - 1], ' ');
		while ((*info)->tail->next != NULL)
			(*info)->tail= (*info)->tail->next;
		while (str[i] != NULL)
			i++;
		while (i > 0)
			newnode((*info)->tail,  str[--i]);
		argc--;
		ft_free(str);
		i = 0;
	}
	(*info)->tail = (*info)->tail->next;
	(*info)->head = node;
	(*info)->head->start_size = list_size((*info)->head);
	(*info)->head->size = list_size((*info)->head);
}

void	init_list(t_point **A_info, t_point **B_info, t_arr_info **arr_info)
{
	*A_info = (t_point *)wrap_malloc(sizeof(t_point));
	*B_info = (t_point *)wrap_malloc(sizeof(t_point));
	*arr_info = (t_arr_info *)wrap_malloc(sizeof(t_arr_info));
	(*A_info)->head = (t_list *)wrap_malloc(sizeof(t_list));
	(*A_info)->tail = (t_list *)wrap_malloc(sizeof(t_list));
	(*B_info)->head = (t_list *)wrap_malloc(sizeof(t_list));
	(*B_info)->tail = (t_list *)wrap_malloc(sizeof(t_list));
	(*B_info)->head->size = 0;
}