# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/10 21:06:17 by oidrissi          #+#    #+#              #
#    Updated: 2021/07/14 00:34:18 by amaghat          ###   ########.fr        #
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