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

int	ft_len_chunk(t_node *stack)
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

void     midpoint_finder(t_node *stack)
{
	int		chunk;
	int		*array;
	int		i;
    int     j;
	int		midpoint;
	t_node	*tmp;

	i = 0;
	tmp = stack;
	chunk = stack->chunk;
	array = (int *)malloc(sizeof(int) * stack_length(stack));
	while (tmp && tmp->chunk == chunk)
	{
		array[i] = tmp->value;
        printf("%d\n", array[i]);
		tmp = tmp->next;
        i++;
	}
	bubblesort(array, ft_len_chunk(tmp));
	midpoint = array[ft_len_chunk(stack) / 2];
	free(array);
	//return (midpoint);
}

void	sort(t_data *data)
{
	t_node *tmp;

	tmp = data->stack_a;
	midpoint_finder(tmp);
	// while (tmp)
	// {
	// 	if (tmp->value < midpoint_finder(tmp))
	// 		exec_instruction("pb", data);
    //     // printf("Second Midpoint is: %d\n" ,midpoint_finder(argv, argc));
	// 	tmp = tmp->next;
	// }
	// update(argv);
}

// void    sort(t_data *data, int argc)
// {
//     int midpoint;
// }