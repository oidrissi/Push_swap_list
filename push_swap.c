/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 21:11:15 by oidrissi          #+#    #+#             */
/*   Updated: 2021/07/12 21:54:12 by oidrissi         ###   ########.fr       */
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

int		is_dup(t_node *stack)
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
					write(2, "Error\n", 6);
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
	init_data(data);
	if (argc == 1 || argc == 2)
		return 0;
	data->stack_a = fill_stacks(argv, argc);
	if (is_sorted(data->stack_a) == 1 || is_dup(data->stack_a) == 1)
		return (ft_clear(&data));
	if (stack_length == 2)
		exec_save("sa", data);
    print_list(data->stack_a);
	// printlist_cmds(data->cmd_list);
	ft_clear(&data);
	return (1);
}