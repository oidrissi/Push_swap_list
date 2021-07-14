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

int	fastest_to_top(t_data *data, int *i, int pos, int j)
{
	int	len;

	if (j == 0)
		len = stack_length(data->stack_a);
	else
		len = stack_length(data->stack_b);
	*i = 0;
	if (pos <= len / 2)
	{
		*i = pos - 1;
		return (1);
	}
	else
	{
		*i = len - pos + 1;
		return (0);
	}
}

// int    smart_push(t_data *data, int i, int j)
// {
//     int     least_moves1;
//     int     least_moves2;

//     least_moves1 = 0;
//     least_moves2 = 0;
//     while (i > 0)
//     {
//         i--;
//         least_moves1++;
//     }
//     while (j < stack_length(data->stack_a))
//     {
//         j++;
//         least_moves2++;
//     }
//     if (least_moves1 > least_moves2)
//     {
//         while (least_moves2 > 0)
//         {
//             exec_instruction("rra", data);
//             least_moves2--;
//         }
//         return (1);
//         exec_instruction("pb", data);
//     }
//     else
//     {
//         while(least_moves1 > 0)
//         {
//             exec_instruction("ra", data);
//             least_moves1--;
//         }
//         exec_instruction("pb", data);
//         return(2);
//     }
//     return (0);
// }

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

int    sort_converted_table(char **argv, int argc)
{
    int		table[argc - 1];
    int		i;
	int 	mid;

    i = 1;
    while (i < argc - 1)
    {
        table[i - 1] = ft_atoi(argv[i]);
        i++;
    }
    bubbleSort(table, argc);
	//sorted, we now look for the midpoint in our table = i / 2;
	mid = table[i / 2];
	return (mid);
}

void     midpoint_finder_a(int argc, char **argv)
{
    // t_node *tmp;
    // int     total;
    int     mid;

	mid = sort_converted_table(argv, argc);
	printf("MID is element number: %d\n", mid);
}

// void    sort(t_data *data, int argc)
// {
//     int midpoint;
// }