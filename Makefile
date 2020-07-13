NAME    = libftprintf.a
PROJECT_NAME = libftprintf
EXE = ft_libftprintf

FLAGS   = -Wall -Werror -Wextra
CFLAGS  = $(FLAGS) -I. -c

C_LIBFT = libft/ft_atoi.c libft/ft_bzero.c libft/ft_isalnum.c libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c libft/ft_itoa.c libft/ft_lstadd.c libft/ft_lstdel.c libft/ft_lstdelone.c libft/ft_lstiter.c libft/ft_lstmap.c libft/ft_lstnew.c libft/ft_lstsize.c libft/ft_max.c libft/ft_memalloc.c libft/ft_memccpy.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_memcpy.c libft/ft_memdel.c libft/ft_memmove.c libft/ft_memset.c libft/ft_min.c libft/ft_putchar.c libft/ft_putchar_fd.c libft/ft_putendl.c libft/ft_putendl_fd.c libft/ft_putnbr.c libft/ft_putnbr_fd.c libft/ft_putstr.c libft/ft_putstr_fd.c libft/ft_strcat.c libft/ft_strchr.c libft/ft_strclr.c libft/ft_strcmp.c libft/ft_strcpy.c libft/ft_strdel.c libft/ft_strdup.c libft/ft_strequ.c libft/ft_striter.c libft/ft_striteri.c libft/ft_strjoin.c libft/ft_strlcat.c libft/ft_strlen.c libft/ft_strmap.c libft/ft_strmapi.c libft/ft_strncat.c libft/ft_strncmp.c libft/ft_strncpy.c libft/ft_strnequ.c libft/ft_strnew.c libft/ft_strnlen.c libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strrev.c libft/ft_strsplit.c libft/ft_strstr.c libft/ft_strsub.c libft/ft_strtrim.c libft/ft_strzero.c libft/ft_swap.c libft/ft_tolower.c libft/ft_toupper.c
C_PRINTF = ft_printf/ft_itoa.c \
		   ft_printf/ft_printf.c

HEADERS = libft/libft.h \
		  includes/ft_printf.h

O_LIBFT  = $(C_LIBFT:.c=.o)
O_PRINTF = $(C_PRINTF:.c=.o)
DIR_O    = objects

CC = @gcc

all: $(NAME)

$(NAME): $(O_LIBFT) $(O_PRINTF) $(HEADERS)
	@ar rcs $(NAME) $(O_LIBFT) $(O_PRINTF)
	@ranlib $(NAME)
	@echo "\033[1;36m$(PROJECT_NAME)		\033[1;32m[✓]\033[0;37m"

(DIR_O)/%.o: %.c
	$(CC) $(CFLAGS) $<

exe : $(NAME)
	@gcc -o $(EXE) -I. main.c $(NAME)

clean:
	@rm -rf $(O_LIBFT) $(O_PRINTF)
	@rm -rf *.gch
	@rm -rf $(EXE).dSYM
	@rm -f .DS_Store
	@echo "\033[1;33mclean 	\033[1;36m$(PROJECT_NAME)	\033[1;32m[✓]\033[0;37m"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(EXE)
	@rm -rf a.out
	@echo "\033[1;33mfclean 	\033[1;36m$(PROJECT_NAME)	\033[1;32m[✓]\033[0;37m"

re: fclean all