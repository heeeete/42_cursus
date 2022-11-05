/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:37:14 by huipark           #+#    #+#             */
/*   Updated: 2022/11/05 22:14:36 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_list	*newnode(t_list *head, char *str)
{
	t_list	*newnode;

	while (head->next != NULL)
		head = head->next;
	newnode = (t_list *)malloc(sizeof(t_list));
	if (!newnode)
		return (0);
	newnode->value = ft_atoi(str);
	newnode->next = NULL;
	newnode->prev = head;
	head->next = newnode;
	return (head);
}

t_list	*init_value(t_list **head, int argc, char *argv[])
{
	t_list	*node;
	char	**str;
	int		i;

	i = 0;
	node = *head;
	while (argc != 1)
	{
		str = ft_split(argv[argc - 1], ' ');
		while ((*head)->next != NULL)
			*head = (*head)->next;
		while (str[i] != NULL)
			i++;
		while (i > 0)
			newnode(*head, str[--i]);
		argc--;
		ft_free(str);
		i = 0;
	}
	(*head) = (*head)->next;
	return (node);
}

int	init_list(t_list **A, t_list **B, t_point **A_info , t_point **B_info)
{
	*A = (t_list *)malloc(sizeof(t_list));
	*B = (t_list *)malloc(sizeof(t_list));
	*A_info = (t_point *)malloc(sizeof(t_point));
	*B_info = (t_point *)malloc(sizeof(t_point));
	if (!(*A) || !(*B) || !(*A_info) || !(*B_info))
		return (1);
	(*B_info)->head = *B;
	(*B_info)->tail = *B;
	return (0);
}