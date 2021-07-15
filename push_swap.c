/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 21:11:15 by oidrissi          #+#    #+#             */
/*   Updated: 2021/07/15 04:07:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int		main(int	argc, char	**argv)
{
	t_data	*data;
	
	data = malloc(sizeof(t_data));
	init_data(data, argc);
	if (argc == 1 || argc == 2 || !correct_input(argv, data))
		return (ft_clear(&data));
	data->stack_a = fill_stacks(argv, argc, &data);
	if (is_sorted(data->stack_a) == 1 || is_dup(data->stack_a, data) == 1)
		return (ft_clear(&data));
	if (stack_length(data->stack_a) == 2)
		exec_instruction("sa", data);
	if (stack_length(data->stack_a) == 3)
		sort_3(data);
	if (stack_length(data->stack_a) == 4)
		sort_4(data);
	if (stack_length(data->stack_a) >= 5)
		sort(data);
	print_instruction_list(data->instruction_list);
	ft_clear(&data);
	return (1);
}