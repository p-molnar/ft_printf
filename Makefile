NAME := libftprintf.a
SRC = ft_printf.c src/ft_printf_utils.c src/write.c src/write_2.c src/write_util.c
CC = gcc
CFLAGS ?= -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

 %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re