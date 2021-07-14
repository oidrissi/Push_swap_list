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

void bubbleSort(int array[], int n) 
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

int    midpoint_finder_a(char **argv, int argc)
{
    int		table[argc - 1];
    int		i;
	int 	mid;

    i = 1;
    while (i <= argc - 1)
    {
        table[i - 1] = ft_atoi(argv[i]);
        i++;
    }
    bubbleSort(table, argc);
	mid = table[(argc - 1) / 2];
	return (mid);
}

void	sort(t_data *data, char **argv, int argc)
{
	t_node *tmp;

	tmp = data->stack_a;
	printf("Midpoint is: %d\n" ,midpoint_finder_a(argv, argc));
	while (tmp)
	{
		if (tmp->value < midpoint_finder_a(argv, argc))
		{
			exec_instruction("pb", data);
			argv++;
		}
		tmp = tmp->next;
	}
	// update(argv);
}

// void    sort(t_data *data, int argc)
// {
//     int midpoint;
// }