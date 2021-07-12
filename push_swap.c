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

int		main(int	argc, char	**argv)
{
	t_data	*data;
	
	data = malloc(sizeof(t_data));
	init_data(data);
	if (argc == 1 || argc == 2)
		return 0;
	data->stack_a = fill_stacks(argv, argc);
	// if (is_sorted(data->stack_a) == 1)
	// 	return (ft_clear(&data));
	
	while (data->stack_a->next != NULL)
    {
        print_list(data->stack_a);
        data->stack_a = data->stack_a->next;
    }
	// printlist_cmds(data->cmd_list);
	// ft_clear(&data);
	return (1);
}