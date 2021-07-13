#include "push_swap.h"

int		ft_strcmp(char *s, char *comp)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != comp[i])
			return (1);
		i++;
	}
	return (0);	
}

int	find_highest(t_node *stack)
{
	t_node	*tmp;
	int		highest;
	int		i;

	tmp = stack;
	i = 1;
	highest = -2147483648;
	while (tmp != NULL)
	{
		if (tmp->value > highest)
			highest = tmp->value;
		tmp = tmp->next;
	}
	tmp = stack;
	while (tmp)
	{
		if (tmp->value == highest)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

int	find_lowest(t_node *stack)
{
	t_node	*tmp;
	int		highest;
	int		i;

	tmp = stack;
	i = 1;
	highest = -2147483648;
	while (tmp != NULL)
	{
		if (tmp->value > highest)
			highest = tmp->value;
		tmp = tmp->next;
	}
	tmp = stack;
	while (tmp)
	{
		if (tmp->value == highest)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (0);
}
