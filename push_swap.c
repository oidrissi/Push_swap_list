/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 21:11:15 by oidrissi          #+#    #+#             */
/*   Updated: 2021/07/10 21:53:44 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
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
	return (0);
}
void	init_data(t_data *data)
{
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->instruction_list = NULL;
}

int		is_sorted(t_data *data)
{
	t_node *list;
	
	list = data->stack_a;
	while (list)
	{
		if (list->value > list->next->value)
			return (0);
		list = list->next;
	}
	return (1);
}

t_node	*create_new_node(int elem)
{
	t_node *tmp;

	tmp = (t_node *)malloc(sizeof(t_node));
	tmp->value = elem;
	tmp->next = NULL;
	return (tmp);
	//tmp = data->stack_a;
}

void	add_back(t_node **tmp, t_node)
{
	
}

int		fill_stacks(char **argv, t_data *data, int argc)
{
	int elems;
	int i;
	t_node *tmp;

	i = 1;
	elems = ac - 1;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648)
			write(2, "Error\n", 6);
		i++;
	}
	i = 1;
	while (elems > 0)
	{
		add_back(&(tmp), create_new_node(ft_atoi(argv[i])));
		elems--;
	}
	return (tmp);
}

int		main(int	argc, char	**argv)
{
	t_data	*data;
	
	data = malloc(sizeof(t_data));
	if (is_sorted(data) == 1)
		printf("sorted");
		// return (ft_clear(&data));
	if (argc == 1 || argc == 2)
		return 0;
}