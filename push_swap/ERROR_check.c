/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ERROR_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:47:35 by huipark           #+#    #+#             */
/*   Updated: 2022/11/06 17:00:40 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ERROR_check(int argc, char *argv[])
{
	int		i;
	int		j;
	char	**str;

	while (argc-- > 1)
	{
		i = 0;
		str = ft_split(argv[argc], ' ');
		while (str[i])
		{
			j = 0;
			while (str[i][j])
			{
				j += (str[i][0] == '-' && j == 0);
				if (str[i][j] < '0' || str[i][j] > '9')
					return (1);
				j++;
			}
			if (ft_atoi(str[i]) > INT_MAX || ft_atoi(str[i]) < INT_MIN)
				return (1);
			i++;
		}
	}
	ft_free(str);
	return (0);
}

int	ERROR_check2(t_list *head)
{
	t_list	*temp;

	while (head->next != NULL)
	{
		head = head->next;
		if (head->next != NULL)
			temp = head->next;
		while (temp != NULL)
		{
			if (head->value == temp->value)
				return (1);
			temp = temp->next;
		}
	}
	return (0);
}
