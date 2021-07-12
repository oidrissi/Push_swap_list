/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 20:05:34 by oidrissi          #+#    #+#             */
/*   Updated: 2021/07/12 20:33:36 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_data *data)
{
	t_node	*tmp;

	if (!data->stack_b)
		return ;
	tmp = data->stack_b;
	data->stack_b = (data->stack_b)->next;
	tmp->next = data->stack_a;
	data->stack_a = tmp;
}

void	pb(t_data *data)
{
	t_node	*tmp;

	if (!data->stack_a)
		return ;
	tmp = data->stack_a;
	data->stack_a = (data->stack_a)->next;
	tmp->next = data->stack_b;
	data->stack_b = tmp;
}

void	sa(t_data *data)
{
	int	tmp;

	if (!data->stack_a || !(data->stack_a)->next)
		return ;
	tmp = (data->stack_a)->value;
	(data->stack_a)->value = (data->stack_a)->next->value;
	(data->stack_a)->next->value = tmp;
}

void	sb(t_data *data)
{
	int		tmp;

	if (!data->stack_b || !(data->stack_b)->next)
		return ;
	tmp = (data->stack_b)->value;
	(data->stack_b)->value = (data->stack_b)->next->value;
	(data->stack_b)->next->value = tmp;
}

void	ss(t_data *data)
{
	sa(data);
	sb(data);
}
