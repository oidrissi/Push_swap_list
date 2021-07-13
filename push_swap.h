/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 21:06:46 by oidrissi          #+#    #+#             */
/*   Updated: 2021/07/13 21:06:15 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <limits.h>
# include <string.h>

typedef struct s_node
{
	int				value;
	char			*instruction;
	int				stack_size_a;
	int				stack_size_b;
	struct s_node	*next;
}				t_node;

typedef struct s_data
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*instruction_list;
}               t_data;

int			find_lowest(t_node *stack);
t_node		*ft_listlast(t_node *list);
int			ft_isdigit(int c);
long long	ft_atoi(const char *str);
int			ft_clear(t_data **data);
void		init_data(t_data *data);
t_node		*fill_stacks(char **argv, int argc);
void		print_list(t_node *head);
void		exec_instruction(char *str, t_data *data);
void		add_back(t_node **head, t_node *to_insert);
int			is_sorted(t_node *stack);
int			correct_input(char **tab);
int			find_highest(t_node *stack);
void		sort_3(t_data *data);
int			stack_length(t_node	*stack);
int			ft_strcmp(char *s, char *comp);
void		pa(t_data *data);
void		pb(t_data *data);
void		sa(t_data *data);
void		sb(t_data *data);
void		ss(t_data *data);
void		ra(t_data *data);
void		rra(t_data *data);
void		rb(t_data *data);
void		rrb(t_data *data);
void    	sort_4(t_data *data);
// void		rr(t_data *data);
// void		rrr(t_data *data);

#endif