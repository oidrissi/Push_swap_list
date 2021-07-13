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

void    smart_push(t_data *data, int i, int j)
{
    int     least_moves1;
    int     least_moves2;

    least_moves1 = 0;
    least_moves2 = 0;
    while (i > 0)
    {
        i--;
        least_moves1++;
    }
    while (j < stack_length(data->stack_a))
    {
        j++;
        least_moves2++;
    }
    if (least_moves1 > least_moves2)
    {
        printf("%d\n")
        while(least_moves2 > 0)
        {
            exec_instruction("rra", data);
            least_moves2--;
        }
        exec_instruction("pb", data);
    }
    else
    {
        while(least_moves1 > 0)
        {
            exec_instruction("ra", data);
            least_moves1--;
        }
        exec_instruction("pb", data);
    }
}

void    sort_4(t_data *data)
{
    int		i;
    int     j;

    j = find_lowest(data->stack_a);
    // printf("%d\n", j);
	i = find_highest(data->stack_a);
    // printf("%d\n", i);
    if (j == 1 || i == 1)
    {
        exec_instruction("pb", data);
        sort_3(data);
        if (j == 1)
        {
            exec_instruction("pa", data);
            exec_instruction("ra", data);
        }
        else
            exec_instruction("pa", data);
    }
    else
    {
        smart_push(data, i, j);
        sort_3(data);
    }
}