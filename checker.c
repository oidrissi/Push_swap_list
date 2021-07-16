/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 04:22:11 by oidrissi          #+#    #+#             */
/*   Updated: 2021/07/15 04:22:11 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

int	is_oper(char *line)
{
	char	**tokens;
	int		i;

	i = 0;
	tokens = ft_split("pa pb sa sb ss ra rb rr rra rrb rrr", ' ');
	while (tokens[i])
	{
		if (!strcmp(tokens[i], line))
		{
			free_tokens(tokens);
			return (1);
		}
		i++;
	}
	free_tokens(tokens);
	return (0);
}

int	log_error(char *err, char **line, t_data **data)
{
	ft_clear(data);
	ft_putstr_fd(err, 2);
	free(*line);
	return (1);
}

int	main(int argc, char **argv)
{
	char	*line;
	t_data	*data;

	data = malloc(sizeof(t_data));
	init_data(data, argc);
	if (argc == 1 || !correct_input(argv, data))
		return (ft_clear(&data));
	data->stack_a = fill_stacks(argv, argc, &data);
	is_dup(data->stack_a, data);
	while (get_next_line(0, &line))
	{
		if (!is_oper(line))
			return (log_error("Error\n", &line, &data));
		exec_instruction(line, data);
		free(line);
	}
	if (data->stack_a && !data->stack_b && is_sorted(data->stack_a) == 1)
		ft_putstr_fd("OK\n", 2);
	else
		ft_putstr_fd("KO\n", 2);
	return (0);
}
