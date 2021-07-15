/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 20:18:08 by oidrissi          #+#    #+#             */
/*   Updated: 2021/07/15 10:04:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_data(t_data *data, int argc)
{
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->nb_elements = argc - 1;
	data->instruction_list = NULL;
}

void	free_node(t_node	**node)
{
	t_node	*tmp;
	
	while (*node)
	{
		tmp = *node;
		*node = (*node)->next;
		if (tmp->instruction)
			free(tmp->instruction);
		free(tmp);
	}
}

int		ft_clear(t_data **data)
{
	free_node(&((*data)->stack_a));
	free_node(&((*data)->stack_b));
	free_node(&((*data)->instruction_list));
	free(*data);
	return (1);
}

void	rr(t_data *data)
{
	ra(data);
	rb(data);
}
