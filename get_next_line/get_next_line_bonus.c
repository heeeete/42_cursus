/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:09:59 by huipark           #+#    #+#             */
/*   Updated: 2022/09/03 19:20:12 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	node_free(t_list **head, t_list **current)
{
	(*current)->prev->next = (*current)->next;
	if ((*current)->next)
		(*current)->next->prev = (*current)->prev;
	free(*current);
	*current = NULL;
	if (!((*head)->next))
	{
		free(*head);
		*head = NULL;
	}
}

t_list	*fd_check(t_list *head, int fd)
{
	t_list	*newnode;

	while (head -> next)
	{
		head = head -> next;
		if (head -> fd == fd)
			return (head);
	}
	newnode = (t_list *)malloc(sizeof(t_list));
	if (!newnode)
		return (NULL);
	newnode -> fd = fd;
	newnode -> backup = NULL;
	newnode -> next = NULL;
	newnode -> prev = head;
	head -> next = newnode;
	return (newnode);
}

char	*check(char *line)
{
	int		i;
	char	*res;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\0' || line[i + 1] == '\0')
		return (NULL);
	res = ft_strdup(&line[i + 1]);
	if (!res)
		return (NULL);
	line[i + 1] = '\0';
	return (res);
}

static char	*get_read(int fd, char *line)
{
	char	*buf;
	char	*temp_address;
	ssize_t	size;

	size = 1;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (size)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size == -1 || size == 0)
			break ;
		buf[size] = '\0';
		temp_address = line;
		line = ft_strjoin(line, buf);
		free(temp_address);
		if (!line || ft_strchr(line, '\n'))
			break ;
	}
	free(buf);
	return (line);
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list			*temp;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!head)
	{
		head = (t_list *)malloc(sizeof(t_list));
		if (!head)
			return (NULL);
		head -> next = NULL;
	}
	temp = fd_check(head, fd);
	line = get_read(fd, temp -> backup);
	if (!line)
	{
		node_free(&head, &temp);
		return (NULL);
	}
	temp -> backup = check(line);
	return (line);
}
