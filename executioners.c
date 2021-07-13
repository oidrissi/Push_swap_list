#include "push_swap.h"

void	exec(char *str, t_data *data)
{
	if (!(strcmp(str, "sa")))
		sa(data);
	else if (!(strcmp(str, "sb")))
		sb(data);
	else if (!(strcmp(str, "ss")))
		ss(data);
	else if (!(strcmp(str, "pa")))
		pa(data);
	else if (!(strcmp(str, "pb")))
		pb(data);
	else if (!(strcmp(str, "ra")))
		ra(data);
	else if (!(strcmp(str, "rb")))
		rb(data);
	else if (!(strcmp(str, "rra")))
		rra(data);
	else if (!(strcmp(str, "rrb")))
		rrb(data);
	else if (!(strcmp(str, "rrr")))
		rrr(data);
	else if (!(strcmp(str, "rr")))
		rr(data);
}

void	exec_save(char *str, t_data *data)
{
	exec(str, data);
	add_back(&(data->cmd_list), create_new_node2(str));
}
