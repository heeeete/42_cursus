/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:47:07 by huipark           #+#    #+#             */
/*   Updated: 2022/12/20 19:47:46 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_perror(char *msg)
{
	perror(msg);
	exit(1);
}

void	ft_close(int fd, int fd2)
{
	close(fd);
	close(fd2);
}