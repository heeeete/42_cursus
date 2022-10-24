/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:37:14 by huipark           #+#    #+#             */
/*   Updated: 2022/10/24 17:09:27 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *newnode(t_list **head, char *argv)
{
	t_list	*newnode;

	newnode = (t_list *)malloc(sizeof(t_list));
	newnode->value = ft_atoi(argv);
	newnode->next = NULL;
	newnode->prev = *head;
	(*head)->next = newnode;
	return (newnode);
}

t_list *init_value(t_list **head, int argc, char *argv[])
{
	t_list *top;

	while (argc)
	{
		
	}
}