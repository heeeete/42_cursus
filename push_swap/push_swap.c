/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:00:42 by huipark           #+#    #+#             */
/*   Updated: 2022/11/05 22:41:47 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_A;
	t_list	*stack_B;
	t_point	*A_info;
	t_point	*B_info;

	if (init_list(&stack_A, &stack_B, &A_info, &B_info))
		return (0);
	A_info->head = init_value(&stack_A, argc, argv);
	if (!(A_info->head))
		return (0);
	A_info->tail = stack_A;
	if (ERROR_check(argc, argv) || ERROR_check3(A_info->head))
	{
		ft_putstr("Error");
		return (0);
	}
	// sa(&A_info);
	// pb(&A_info, &B_info);
	// pb(&A_info, &B_info);
	// pb(&A_info, &B_info);
	// rr(&A_info, &B_info);
	// rrr(&A_info, &B_info);
	// sb(&B_info);
	while (A_info ->head->next != NULL)
	{
		A_info->head = A_info->head->next;
		printf("stack A head %d\n", A_info->head->value);
	}
	printf("\n\n");
	while (B_info ->head->next != NULL)
	{
		B_info->head = B_info->head->next;
		printf("stack B %d\n", B_info->head->value);
	}
	printf("\n\n");
	while (A_info ->tail->prev != NULL)
	{
		printf("stack A %d\n", A_info->tail->value);
		A_info->tail = A_info->tail->prev;
	}
	printf("\n\n");
	while (B_info ->tail->prev != NULL)
	{
		printf("stack B %d\n", B_info->tail->value);
		B_info->tail = B_info->tail->prev;
	}
}