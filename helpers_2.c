/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 21:01:58 by oidrissi          #+#    #+#             */
/*   Updated: 2021/07/13 21:01:58 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_strcmp(char *s, char *comp)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != comp[i])
			return (1);
		i++;
	}
	return (0);	
}

void	ft_puterror(char *error, t_data **data)
{
	ft_clear(data);
	ft_putstr_fd(error, 2);
	exit(-1);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
		{
			ft_putchar_fd(*s, fd);
			s++;
		}
	}
}

