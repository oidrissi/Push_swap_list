/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 21:06:46 by oidrissi          #+#    #+#             */
/*   Updated: 2021/07/15 10:37:02 by marvin           ###   ########.fr       */
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
# include <math.h>

typedef struct s_node
{
	int				value;
	char			*instruction;
	int				chunk;
	struct s_node	*next;
}				t_node;

typedef struct s_data
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*instruction_list;
	int		nb_elements;
}               t_data;

void		bubblesort(int array[], int n);
void		swap(int *a, int *b) ;
void		print_instruction_list(t_node *head);
int			is_sorted(t_node *stack);
int			chunk_sorted(t_node *node);
int			find_lowest(t_node *stack);
int			find_highest(t_node *stack);
int			ft_isdigit(int c);
int			correct_input(char **tab, t_data *data);
int			is_dup(t_node *stack, t_data *data);
void		ft_puterror(char *error, t_data **data);
long long	ft_atoi(const char *str);
int			ft_clear(t_data **data);
size_t		ft_strlen(const char *str);
char		**ft_split(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(const char *s);
int			get_next_line(int fd, char **line);
void		init_data(t_data *data, int argc);
t_node		*fill_stacks(char **argv, int argc, t_data **data);
void		ft_putstr_fd(char *s, int fd);
t_node		*ft_listlast(t_node *list);
void		print_list(t_node *head);
void		exec_instruction(char *str, t_data *data);
void		add_back(t_node **head, t_node *to_insert);
void		sort_3(t_data *data);
int			stack_length(t_node	*stack);
int			len_chunk(t_node *stack);
int			ft_strcmp(char *s, char *comp);
void		smart_push_rotate(t_data *data, int rot);
int     	midpoint_finder(t_node *stack);
int			higher_than_midpoint(t_node *node, int midpoint);
int			lower_than_midpoint(t_node *node, int midpoint);
void		finish_chunk(t_data *data, t_node *tmp);
void		sort(t_data *data);
void		pa(t_data *data);
void		pb(t_data *data);
void		sa(t_data *data);
void		sb(t_data *data);
void		ss(t_data *data);
void		ra(t_data *data);
void		rra(t_data *data);
void		rb(t_data *data);
void		rrb(t_data *data);
void		rr(t_data *data);
void		rrr(t_data *data);

#endif