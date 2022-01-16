NAME := libftprintf.a
SRC =	ft_printf.c src/ft_printf_utils.c \
		src/print_arg.c src/put.c src/put_2.c src/write_utils.c \
		src/populate_specifier_struct.c src/print_arg_utils.c

CC = gcc
CFLAGS ?= -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
#ar rcs $(NAME) $(OBJ)
	make libft/libft.a
	cp libft/libft.a .
	mv libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)

 %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re