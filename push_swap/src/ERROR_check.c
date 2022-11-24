/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ERROR_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:47:35 by huipark           #+#    #+#             */
/*   Updated: 2022/11/24 16:25:41 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	error_check3(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i += ((str[0] == '-' || str[0] == '+') && i == 0);
		if (str[i] < '0' || str[i] > '9')
			error();
		i++;
	}
	if (ft_atoi(str) > INT_MAX || ft_atoi(str) < INT_MIN)
		error();
}

void	error_check(int argc, char *argv[])
{
	int		i;
	char	**str;

	while (argc-- > 1)
	{
		i = 0;
		str = ft_split(argv[argc], ' ');
		while (str[i])
		{
			error_check3(str[i]);
			i++;
		}
		if (!str[0])
			error();
		ft_free(str);
	}
}

void	error_check2(int argc, t_list *head)
{
	t_list	*temp;

	if (argc == 1)
		exit(0);
	while (head->next != NULL && argc != 2)
	{
		head = head->next;
		if (head->next != NULL)
			temp = head->next;
		while (temp != NULL)
		{
			if (head->value == temp->value)
				error();
			temp = temp->next;
		}
	}
}
