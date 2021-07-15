/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:16:35 by marvin            #+#    #+#             */
/*   Updated: 2021/07/15 10:16:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"
#include "push_swap.h"

static int	get_line(char **s, char **line)
{
	int		i;
	char	*saved;

	i = 0;
	while (*s && (*s)[i] != '\n' && (*s)[i] != '\0')
		i++;
	if (*s && (*s)[i] == '\n')
	{
		*line = ft_substr(*s, 0, i);
		saved = ft_strdup(&((*s)[i + 1]));
		free(*s);
		*s = saved;
	}
	else
	{
		*line = ft_strdup(*s);
		free(*s);
		*s = NULL;
		return (0);
	}
	return (1);
}

static int	helper(char **s, char **line, int l, int fd)
{
	if (l < 0)
		return (-1);
	else if (l == 0 && s[fd] == NULL)
	{
		*line = ft_strdup("");
		return (0);
	}
	else
		return (get_line(&s[fd], line));
}

int			get_next_line(int fd, char **line)
{
	int			l;
	static char	*s[FD_SIZE];
	char		*buff;
	char		*saved;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0 ||
			(!(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)))))
		return (-1);
	while ((l = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[l] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strdup(buff);
		else
		{
			if (!(saved = ft_strjoin(s[fd], buff)))
				return (-1);
			free(s[fd]);
			s[fd] = saved;
		}
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	free(buff);
	return (helper(s, line, l, fd));
}