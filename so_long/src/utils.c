/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:27:55 by huipark           #+#    #+#             */
/*   Updated: 2022/12/03 21:37:51 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	*wrap_malloc(size_t s)
{
	void	*ret;

	ret = malloc(s);
	if (ret == NULL)
		exit (1);
	return (ret);
}

void	exit_game(t_game *game)
{
	printf("--------\nGAME END\n--------\n");
	exit(0);
}

void	error(char *msg)
{
	printf("%s\n", msg);
	exit(1);
}