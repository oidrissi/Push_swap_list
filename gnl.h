/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:17:27 by marvin            #+#    #+#             */
/*   Updated: 2021/07/15 10:17:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 10

# include <stdlib.h>
# include <unistd.h>

int         get_next_line(int fd, char **line);
int			has_return(char *str);
size_t		ft_strlen(const char *s);
char		*join_str(const char *s1, const char *s2);

#endif