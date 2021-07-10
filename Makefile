# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/10 21:06:17 by oidrissi          #+#    #+#              #
#    Updated: 2021/07/10 21:06:22 by oidrissi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

SRCS = *.c

OBJECTS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror


all: $(NAME)


$(NAME) : 
		$(CC) $(CFLAGS) -c $(SRCS) -I ./
		ar rc $(NAME) $(OBJECTS)
		ranlib $(NAME)
clean:
		rm -f $(OBJECTS)

fclean: 
		rm -f $(OBJECTS)
		rm -f $(NAME)

re: fclean all

bonus: