/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 16:44:39 by oidrissi          #+#    #+#             */
/*   Updated: 2021/07/16 16:44:39 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	finish_chunk(t_data *data, t_node *tmp)
{
	if (tmp->next && tmp->value < tmp->next->value)
		exec_instruction("sb", data);
	exec_instruction("pa", data);
	exec_instruction("pa", data);
}

int	chunk_sorted(t_node *node)
{
	int		chunk;
	t_node	*tmp;

	if (!node)
		return (0);
	tmp = node;
	chunk = node->chunk;
	while (tmp->next && tmp->chunk == chunk)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	len_chunk(t_node *stack)
{
	int		len;
	int		chunk;
	t_node	*tmp;

	len = 0;
	tmp = stack;
	chunk = stack->chunk;
	while (tmp && tmp->chunk == chunk)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

int	higher_than_midpoint(t_node *node, int midpoint)
{
	int		chunk;
	t_node	*tmp;

	tmp = node;
	chunk = node->chunk;
	while (tmp && tmp->chunk == chunk)
	{
		if (tmp->value > midpoint)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	lower_than_midpoint(t_node *node, int midpoint)
{
	int		chunk;
	t_node	*tmp;

	tmp = node;
	chunk = node->chunk;
	while (tmp && tmp->chunk == chunk)
	{
		if (tmp->value < midpoint)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
