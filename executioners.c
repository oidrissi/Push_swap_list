#include "push_swap.h"

void	exec(char *str, t_data *data)
{
	if (!(ft_strcmp(str, "sa")))
		sa(data);
	else if (!(ft_strcmp(str, "sb")))
		sb(data);
	else if (!(ft_strcmp(str, "ss")))
		ss(data);
	else if (!(ft_strcmp(str, "pa")))
		pa(data);
	else if (!(ft_strcmp(str, "pb")))
		pb(data);
	else if (!(ft_strcmp(str, "ra")))
		ra(data);
	else if (!(ft_strcmp(str, "rb")))
		rb(data);
	else if (!(ft_strcmp(str, "rra")))
		rra(data);
	else if (!(ft_strcmp(str, "rrb")))
		rrb(data);
	// else if (!(ft_strcmp(str, "rrr")))
	// 	rrr(data);
	// else if (!(ft_strcmp(str, "rr")))
	// 	rr(data);
}

t_node	*create_new_node2(char *str)
{
	t_node	*result;

	result = (t_node *)malloc(sizeof(t_node));
	result->instruction = strdup(str);
	result->next = NULL;
	return (result);
}

void	exec_instruction(char *str, t_data *data)
{
	exec(str, data);
	add_back(&(data->instruction_list), create_new_node2(str));
}
