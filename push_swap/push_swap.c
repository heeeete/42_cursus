/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:00:42 by huipark           #+#    #+#             */
/*   Updated: 2022/10/27 20:22:53 by huipark          ###   ########.fr       */
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

t_list	*newnode(t_list **head, char *argv)
{
	t_list	*newnode;

	newnode = (t_list *)malloc(sizeof(t_list));
	newnode->value = ft_atoi(argv);
	newnode->next = NULL;
	newnode->prev = *head;
	(*head)->next = newnode;
	return (newnode);
}

t_list	*init_value(t_list **head, int argc, char *argv[])
{
	t_list	*node;

	node = *head;
	while (argc != 1)
	{
		*head = newnode(head, argv[argc - 1]);
		argc--;
	}
	return (node);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_A;
	t_list	*stack_B;
	t_list	*A_head;

	if (ERROR_check(argc, argv) || ERROR_check2(argc, argv))
	{
		ft_putstr("Error");
		return (0);
	}
	stack_A = (t_list *)malloc(sizeof(t_list));
	stack_B = (t_list *)malloc(sizeof(t_list));
	if (!stack_A || !stack_B)
		return (0);
	A_head = init_value(&stack_A, argc, argv);
	sa(&stack_A, A_head);
	while (stack_A ->prev != NULL)
	{
		printf("%d\n", stack_A->value);
		stack_A = stack_A->prev;
	}
	
	// printf("%d\n", stack_A->size);
}