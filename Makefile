NAME := libftprintf.a
SRC  := ft_printf.c	\
		src/print_formatted_arg.c	\
		src/formatting.c	\
		src/parse.c	\
		src/parse.c	\
		src/populate_struct.c	\
		src/put.c	\
		utils/ft_printf_formatting_utils.c	\
		utils/ft_printf_utils.c	
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