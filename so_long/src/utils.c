/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:27:55 by huipark           #+#    #+#             */
/*   Updated: 2022/12/05 19:34:23 by huipark          ###   ########.fr       */
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
	printf("%s\n", msg);
	exit(1);
}

void	succsess_game(void)
{
	printf("Congratulations! Success!\n");
	exit(0);
}
