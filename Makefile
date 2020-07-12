

CC = gcc

CFLAGS = -Wall -Wextra #-Werror

NAME = ft_printf

HEADERS = -I . -I libft/

LIBS = -L ./libft/ -lft

OBJS = $(SRCS:.c=.o)

SRCS = srcs/ft_printf.c srcs/ft_itoa.c

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

