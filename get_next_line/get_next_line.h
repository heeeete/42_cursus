/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:37:26 by huipark           #+#    #+#             */
/*   Updated: 2022/09/03 19:23:09 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s1);
char			*get_next_line(int fd);
char			*get_read(int fd, char *backup);
char			*check(char *line);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
size_t			ft_strlen(const char *str);

#endif