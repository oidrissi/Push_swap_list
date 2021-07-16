/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 21:11:15 by oidrissi          #+#    #+#             */
/*   Updated: 2021/07/16 16:43:11 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char	**argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	init_data(data, argc);
	if (argc == 1 || !correct_input(argv, data))
		return (ft_clear(&data));
	data->stack_a = fill_stacks(argv, argc, &data);
	if (is_sorted(data->stack_a) == 1 || is_dup(data->stack_a, data) == 1)
		return (ft_clear(&data));
	else if (stack_length(data->stack_a) == 2)
		exec_instruction("sa", data);
	else if (stack_length(data->stack_a) == 3)
		sort_3(data);
	else if (stack_length(data->stack_a) >= 4)
		sort(data);
	print_instruction_list(data->instruction_list);
	ft_clear(&data);
	return (1);
}
