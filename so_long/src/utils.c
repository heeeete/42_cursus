/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:27:55 by huipark           #+#    #+#             */
/*   Updated: 2022/12/09 17:32:16 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	*wrap_malloc(size_t s)
{
	void	*ret;

	ret = malloc(s);
	if (ret == NULL)
		error ("MALLOC ERROR");
	return (ret);
}

int	exit_game(void)
{
	printf("--------\nGAME END\n--------\n");
	exit(0);
}

void	error(char *msg)
{
	int	len;
	int	len2;

	len = ft_strlen(msg) + 8;
	len2 = ft_strlen(msg) + 8;
	while (len--)
	{
		printf("-");
	}
	printf("\n");
	printf("ERROR = %s\n", msg);
	while (len2--)
	{
		printf("-");
	}
	printf("\n");
	exit(1);
}

void	succsess_game(void)
{
	printf("--------------------------\n");
	printf("Congratulations! Success!\n");
	printf("--------------------------\n");
	exit(0);
}
