# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/10 21:06:17 by oidrissi          #+#    #+#              #
#    Updated: 2021/07/16 16:43:18 by oidrissi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = push_swap
NAMEB = checker

SRC = push_swap.c\
	  bubblesort.c\
	  instructions.c\
	  rotations.c\
	  chunks.c\
	  executioners.c\
	  fill_stack.c\
	  helpers_2.c\
	  helpers.c\
	  sort.c\
	  sort_small.c\
	  stack_data.c\

SRCB = checker.c\
	   bubblesort.c\
	   instructions.c\
	   rotations.c\
	   chunks.c\
	   split.c\
	   executioners.c\
	   fill_stack.c\
	   helpers_2.c\
	   helpers.c\
	   gnl.c\
	   gnl_help.c\
	   sort.c\
	   sort_small.c\
	   stack_data.c\

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(SRC) $(FLAGS) -o $(NAME)

bonus: $(NAMEB)

$(NAMEB): $(SRCB)
	@$(CC) $(SRCB) $(FLAGS) -o $(NAMEB)

fclean:
	@rm -rf $(NAME) $(NAMEB)

re: fclean all