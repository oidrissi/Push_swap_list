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

int     move_lowest_to_top(t_data *data)
{
    int     moves_up;
    int     moves_down;

    moves_up = find_lowest(data->stack_a);
    // printf("%d\n", moves_up);
    if (moves_up == 0)
        return (0);
    moves_down = find_lowest(data->stack_a) - stack_length(data->stack_a);
    if (abs(moves_down) >= moves_up)
        return (moves_up);
    return (moves_down);
}

void    sort_4(t_data *data)
{
    int     absolute;
    int     moves;

    moves = move_lowest_to_top(data);
    absolute = abs(moves);
    if (moves < 0)
    {
        absolute = abs(moves);
        while (absolute > 0)
        {
            exec_instruction("rra", data);
            absolute--;
        }
    }
    else
    {
        absolute = moves;
        while (absolute > 0)
        {
            exec_instruction("ra", data);
            absolute--;
        }
    }
    if (!is_sorted(data->stack_a))
    {
        exec_instruction("pb", data);
        sort_3(data);
        exec_instruction("pa", data);
    }
}

void swap(int *a, int *b) 
{ 
	int temp;

	temp = *a; 
	*a = *b; 
	*b = temp; 
}  

void bubblesort(int array[], int n) 
{ 
    int	i;
	int	j;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (array[j] > array [j + 1])
				swap(&array[j], &array[j+1]);
			j++;
		}
		i++;
	}
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

int		higher_than_midpoint(t_node *node, int midpoint)
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

int		lower_than_midpoint(t_node *node, int midpoint)
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

void	finish_chunk(t_data *data, t_node *tmp)
{
	if (tmp->next && tmp->value < tmp->next->value)
		exec_instruction("sb", data);
	exec_instruction("pa", data);
	exec_instruction("pa", data);
}

void	iter_btoa(t_data *data)
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

void	ft_rev_pushrot(t_data *data)
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
			iter_btoa(data);
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
				ft_rev_pushrot(data);
		}
	}
}

	// int	j;
	// t_node *tmp;
	// int i;
	// int	tab[i];
	// // t_node *tmp_b;
	// // int		top_value;

	// i = 0;
	// tmp = data->stack_a;
	// j = midpoint_finder(data->stack_a);
	// printf("MID: %d\n", j);

	// while (data->stack_a)
	// {
	// 	if (data->stack_a->value < j)
	// 	{
	// 		while (i < data->nb_elements)
	// 		{
	// 			tab[i] = data->stack_a->value;
	// 			i++;
	// 		}
	// 	}	
	// 	data->stack_a->next;
	// }
	// data->stack_a = tmp;
	// while (data->stack_a)
	// {
	// 	if (data->stack_a->value == tab[i])
	// 		exec_instruction("pb", data);
	// 	else
	// 		exec_instruction("ra", data);
	// 	data->stack_a->next;
	// }