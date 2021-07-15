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

int	find_highest(t_node *stack)
{
	t_node	*tmp;
	int		highest;
	int		i;

	tmp = stack;
	i = 1;
	highest = -2147483648;
	while (tmp != NULL)
	{
		if (tmp->value > highest)
			highest = tmp->value;
		tmp = tmp->next;
	}
	tmp = stack;
	while (tmp)
	{
		if (tmp->value == highest)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

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

int		is_sorted(t_node *stack)
{
	t_node *list;
	
	list = stack;
	while (list->next != NULL)
	{
		if (list->value > list->next->value)
			return (0);
		list = list->next;
	}
	return (1);
}

int		is_dup(t_node *stack, t_data *data)
{
	t_node	*tmp;
	t_node	*head;
	int		num;

	head = stack;
	while (stack)
	{
		tmp = head;
		num = 0;
		while (tmp)
		{
			if (tmp->value == stack->value)
			{
				num++;
				if (num > 1)
				{
					ft_puterror("Error\n", &data);
					return (1);
				}
			}
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (0);
}
