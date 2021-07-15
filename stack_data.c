/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 20:14:57 by oidrissi          #+#    #+#             */
/*   Updated: 2021/07/15 05:24:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_new_node(int elem)
{
	t_node *tmp;

	tmp = (t_node *)malloc(sizeof(t_node));
	tmp->value = elem;
	tmp->instruction = NULL;
	tmp->next = NULL;
	return (tmp);
}

int		stack_length(t_node	*stack)
{
	int		stack_length;
	t_node	*tmp;
    
    stack_length = 0;
	tmp = stack;
	while (tmp)
	{
		tmp = tmp->next;
		stack_length++;
	}
	return (stack_length);
}

void	print_instruction_list(t_node *head)
{
	t_node	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		printf("%s\n", tmp->instruction);
		tmp = tmp->next;
	}
}

void	add_back(t_node **head, t_node *to_insert)
{
	to_insert->next = NULL;
	if (!*head)
		*head = to_insert;
	else
		ft_listlast(*head)->next = to_insert;
}


t_node	*fill_stacks(char **argv, int argc, t_data **data)
{
	int i;
	t_node *tmp;

	i = 1;
	tmp = NULL;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648)
		{
			ft_puterror("Error\n", data);
			ft_clear(data);
		}
		i++;
	}
	i = 1;
	while (i < argc)
	{
		add_back(&(tmp), create_new_node(ft_atoi(argv[i])));
		i++;
	}
	return (tmp);
}
