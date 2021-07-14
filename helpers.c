/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 20:07:51 by oidrissi          #+#    #+#             */
/*   Updated: 2021/07/14 01:05:38 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned long long	ret;

	ret = 0;
	sign = 1;
	i = 0;
	while (*(str + i) == '\n' ||
		*(str + i) == '\t' ||
		*(str + i) == '\r' ||
		*(str + i) == '\v' ||
		*(str + i) == '\f' ||
		*(str + i) == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		ret = ret * 10 + (str[i] - 48);
		i++;
	}
	return (ret * sign);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	is_correct(char *str)
{
	int		i;

	i = 0;
	if ((str[0] == '-' || str[0] == '+') && str[1] == '\0')
		return (0);
	if (str[0] == '-' || str[0] == '+')
		str++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int		correct_input(char **tab)
{
	int		i;

	i = 1;
	while (tab[i])
	{
		if (is_correct(tab[i]) == 0)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

t_node	*ft_listlast(t_node *list)
{
	if (!list)
		return (list);
	while (list->next)
		list = list->next;
	return (list);
}
