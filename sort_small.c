/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 21:02:08 by oidrissi          #+#    #+#             */
/*   Updated: 2021/07/13 21:02:08 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_data *data)
{
	int		i;

	i = find_highest(data->stack_a);
	if (i == 1)
	{
		exec_instruction("ra", data);
		if (!is_sorted(data->stack_a))
			exec_instruction("sa", data);
	}
	if (i == 2)
	{
		exec_instruction("rra", data);
		if (!is_sorted(data->stack_a))
			exec_instruction("sa", data);
	}
	if (i == 3)
	{
		if (!is_sorted(data->stack_a))
			exec_instruction("sa", data);
	}
}

int	midpoint_finder(t_node *stack)
{
	int		*array;
	int		i;
	int		midpoint;
	int		chunk;
	t_node	*tmp;

	i = 0;
	tmp = stack;
	chunk = stack->chunk;
	array = (int *)malloc(sizeof(int) * len_chunk(stack));
	while (tmp && tmp->chunk == chunk)
	{
		array[i++] = tmp->value;
		tmp = tmp->next;
	}
	bubblesort(array, len_chunk(stack));
	midpoint = array[len_chunk(stack) / 2];
	free(array);
	return (midpoint);
}
