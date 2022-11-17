/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:00:42 by huipark           #+#    #+#             */
/*   Updated: 2022/11/18 00:10:31 by huipark          ###   ########.fr       */
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

void	set_info(t_arr_info **arr_info, int max_index)
{
	// max_index -= 1;
	
	(*arr_info)->max = (*arr_info)->arr[0];
	(*arr_info)->min = (*arr_info)->arr[max_index - 1];
	(*arr_info)->one_over_three_pivot = (*arr_info)->arr[max_index / 3];
	(*arr_info)->two_over_three_pivot = (*arr_info)->arr[max_index * 2 / 3];
}

void	set_arr(t_arr_info **arr_info, char *argv[])
{
	int		i;
	int		j;
	int		k;
	int		cnt;
	char	**str;

	i = 1;
	k = 0;
	cnt = count(argv);
	(*arr_info)->arr = wrap_malloc(sizeof(int) * cnt);
	i = 1;
	while (argv[i])
	{
		j = 0;
		str = ft_split(argv[i], ' ');
		while (str[j])
			(*arr_info)->arr[k++] = ft_atoi(str[j++]);
		i++;
	}
	free (str);
	quicksort (&(*arr_info)->arr, 0, cnt - 1);
	set_info(arr_info, cnt);
}

int	main(int argc, char *argv[])
{
	t_point		*A_info;
	t_point		*B_info;
	t_arr_info	*arr_info;

	init_list(&A_info, &B_info, &arr_info);
	error_check(argc, argv);
	init_value(&A_info, argc, argv);
	error_check2(argc, A_info->head);
	set_arr(&arr_info, argv);
	separation(A_info, B_info, arr_info);
	sort2(A_info, B_info, arr_info);

	// printf("stack A head\n");
	// while (A_info ->head->next != NULL)
	// {
	// 	A_info->head = A_info->head->next;
	// 	printf("%d\n", A_info->head->value);
	// }
	// printf("\n\n");
	// printf("stack B head\n");
	// while (B_info ->head->next != NULL)
	// {
	// 	B_info->head = B_info->head->next;
	// 	printf("%d\n", B_info->head->value);
	// }
	// printf("\n\n");
	// printf("stack A tail\n");
	// while (A_info ->tail->prev != NULL)
	// {
	// 	printf("%d\n", A_info->tail->value);
	// 	A_info->tail = A_info->tail->prev;
	// }
	// printf("\n\n");
	// printf("stack B tail\n");
	// while (B_info ->tail->prev != NULL)
	// {
	// 	printf("%d    %d\n", B_info->tail->value, B_info->tail->index);
	// 	B_info->tail = B_info->tail->prev;
	// }
}
