/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 04:58:13 by marvin            #+#    #+#             */
/*   Updated: 2021/07/15 04:58:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	a_to_b(t_data *data, int midpoint, int chunk)
{
	if (data->stack_a->value < midpoint)
	{
		exec_instruction("pb", data);
		data->stack_b->chunk = chunk;
		return (0);
	}
	return (1);
}

void	smart_push_rotate(t_data *data, int rot)
{
	int	midpoint;
	int	chunk;
	int	nra;
	
	chunk = data->stack_a->chunk;
	while (!is_sorted(data->stack_a)
		&& len_chunk(data->stack_a) > 2)
	{
		chunk++;
		nra = 0;
		midpoint = midpoint_finder(data->stack_a);
		while (lower_than_midpoint(data->stack_a, midpoint))
		{
			if (a_to_b(data, midpoint, chunk))
			{
				exec_instruction("ra", data);
				nra++;
			}
		}
		while (!rot && nra--)
			exec_instruction("rra", data);
	}
	if (!chunk_sorted(data->stack_a) && len_chunk(data->stack_a) == 2)
		exec_instruction("sa", data);
}

void	b_to_a(t_data *data)
{
	int	midpoint;
	int	nrb;

	nrb = 0;
	midpoint = midpoint_finder(data->stack_b);
	while (higher_than_midpoint(data->stack_b, midpoint))
	{
		if (data->stack_b->value > midpoint)
		{
			exec_instruction("pa", data);
			data->stack_a->chunk++;
			data->stack_a->chunk++;
		}
		else
		{
			exec_instruction("rb", data);
			nrb++;
		}
	}
	while (nrb--)
		exec_instruction("rrb", data);
	smart_push_rotate(data, 0);
}

void	push_rotate_from_b(t_data *data)
{
	t_node	*tmp;
	int		chunk;

	tmp = data->stack_b;
	chunk = tmp->chunk;
	while (tmp && tmp->chunk == chunk)
	{
		if (len_chunk(data->stack_b) == 1)
		{
			exec_instruction("pa", data);
			tmp = data->stack_b;
		}
		else if (len_chunk(data->stack_b) == 2)
		{
			finish_chunk(data, tmp);
			tmp = data->stack_b;
		}
		else
		{
			b_to_a(data);
			tmp = data->stack_b;
		}
		if (tmp)
			tmp = tmp->next;
	}
}

void	sort(t_data *data)
{
	while (!is_sorted(data->stack_a)
		|| stack_length(data->stack_a) != data->nb_elements)
	{
		if (is_sorted(data->stack_a) && !data->stack_b)
			return ;
		else
		{
			if (!is_sorted(data->stack_a))
				smart_push_rotate(data, 1);
			else
				push_rotate_from_b(data);
		}
	}
}
