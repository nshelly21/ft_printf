# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drafe <nshelly@student.42.fr>                +#+  +:+       +#+       #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/12 20:00:16 by nshelly             #+#    #+#            #
#    Updated: 2019/08/31 21:12:56 by nshelly          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = ft_printf

HEADERS = -I includes/ -I libft/

LIBS = -L ./libft/ -lft

OBJS = $(SRCS:.c=.o)

SRCS = srcs/ft_printf.c

all: $(NAME)

$(NAME):$(OBJS) | lib
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<


lib:
	make -C./libft

clean:
	make clean -C./libft
	rm -rf $(OBJS)

fclean: clean
	make fclean -C./libft
	rm -f $(NAME)

re: fclean all

