/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 20:30:05 by oidrissi          #+#    #+#             */
/*   Updated: 2021/07/15 03:43:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *data)
{
	t_node	*head;
	t_node	*tmp;

	if (!data->stack_a || !(data->stack_a)->next)
		return ;
	head = (data->stack_a)->next;
	tmp = data->stack_a;
	ft_listlast(tmp)->next = data->stack_a;
	(data->stack_a)->next = NULL;
	data->stack_a = head;
}

void	rb(t_data *data)
{
	t_node	*head;
	t_node	*tmp;

	if (!data->stack_b || !(data->stack_b)->next)
		return ;
	head = (data->stack_b)->next;
	tmp = data->stack_b;
	ft_listlast(tmp)->next = data->stack_b;
	(data->stack_b)->next = NULL;
	data->stack_b = head;
}

void	rra(t_data *data)
{
	t_node	*last;
	t_node	*second_last;

	last = data->stack_a;
	second_last = NULL;
	if (!data->stack_a || !(data->stack_a)->next)
		return ;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = data->stack_a;
	data->stack_a = last;
}

void	rrb(t_data *data)
{
	t_node	*last;
	t_node	*second_last;

	last = data->stack_b;
	second_last = NULL;
	if (!data->stack_b || !(data->stack_b)->next)
		return ;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = data->stack_b;
	data->stack_b = last;
}

void	rrr(t_data *data)
{
	rra(data);
	rrb(data);
}

void	rr(t_data *data)
{
	ra(data);
	rb(data);
}