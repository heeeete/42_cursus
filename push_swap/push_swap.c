/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:00:42 by huipark           #+#    #+#             */
/*   Updated: 2022/11/08 19:30:58 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

int count(char *argv[])
{
	int		cnt;
	int		i;
	int		j;
	char	**str;

	cnt = 0;
	i = 1;
	while (argv[i])
	{
		j = 0;
		str = ft_split(argv[i], ' ');
		while (str[j])
		{
			cnt++;
			j++;
		}
		free (str);
		i++;
	}
	return (cnt);
}

void	init_arr(int **a, char *argv[])
{
	int		i;
	int		j;
	int		k;
	int		cnt;
	char	**str;

	i = 1;
	k = 0;
	cnt = count(argv);
	printf("cnt = %d", cnt);
	*a = wrap_malloc(sizeof(int) * cnt);
	i = 1;
	while (argv[i])
	{
				printf("I = %d\n", i);

		j = 0;
		str = ft_split(argv[i], ' ');
		while (str[j])
		free (str);
			(*a)[k++] = ft_atoi(str[j++]);
		i++;
	}
	// quicksort (a, 0, sizeof(a) / sizeof(int));
}

int	main(int argc, char *argv[])
{
	t_point	*A_info;
	t_point	*B_info;
	int		*arr;

	init_list(&A_info, &B_info);
	error_check(argc, argv);
	init_value(&A_info, argc, argv);
	error_check2(argc, A_info->head);
	init_arr(&arr, argv);
	arr[5] = NULL;
	int ca = sizeof(arr) / sizeof(int);
	int i = 0;
	while (ca)
	{
		printf("arr = %d   ", arr[i]);
		i++;
		ca--;
	}

	// sa(&A_info);
	// pb(&A_info, &B_info);
	// pb(&A_info, &B_info);
	// pb(&A_info, &B_info);
	// rr(&A_info, &B_info);
	// rrr(&A_info, &B_info);
	// sb(&B_info);
















	
	printf("stack A head\n");
	while (A_info ->head->next != NULL)
	{
		A_info->head = A_info->head->next;
		printf("%d\n", A_info->head->value);
	}
	printf("\n\n");
	printf("stack B head\n");
	while (B_info ->head->next != NULL)
	{
		B_info->head = B_info->head->next;
		printf("%d", B_info->head->value);
	}
	printf("\n\n");
	printf("stack A tail\n");
	while (A_info ->tail->prev != NULL)
	{
		printf("%d\n", A_info->tail->value);
		A_info->tail = A_info->tail->prev;
	}
	printf("\n\n");
	printf("stack B tail\n");
	while (B_info ->tail->prev != NULL)
	{
		printf("%d\n", B_info->tail->value);
		B_info->tail = B_info->tail->prev;
	}
}