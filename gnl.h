/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 16:43:54 by oidrissi          #+#    #+#             */
/*   Updated: 2021/07/16 16:43:54 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H
# define BUFFER_SIZE 10

# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
int		has_return(char *str);
size_t	ft_strlen(const char *s);
char	*join_str(const char *s1, const char *s2);

#endif