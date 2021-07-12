/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 21:06:46 by oidrissi          #+#    #+#             */
/*   Updated: 2021/07/12 21:48:17 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	char			*instruction;
	struct s_node	*next;
}				t_node;

typedef struct s_data
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*instruction_list;
}               t_data;

t_node		*ft_listlast(t_node *list);
int			ft_isdigit(int c);
long long	ft_atoi(const char *str);
int			ft_clear(t_data **data);
void		init_data(t_data *data);
t_node		*fill_stacks(char **argv, int argc);
void		print_list(t_node *head);

#endif