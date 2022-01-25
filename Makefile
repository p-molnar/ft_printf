NAME 		:=	libftprintf.a 
SRC  		:=	ft_printf.c	\
				src/print_formatted_arg.c	\
				src/formatting.c	\
				src/parse.c	\
				src/parse.c	\
				src/populate_struct.c	\
				src/put.c	\
				utils/ft_printf_formatting_utils.c	\
				utils/ft_printf_utils.c	

HEADER_DIR	?=	headers

LIBFT_DIR 	?=	libft
LIBFT		?=	libft.a

CC 			=	gcc
CFLAGS 		?=	-Wall -Wextra -Werror -I headers

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
		cp $(LIBFT_DIR)/$(LIBFT) .
		mv $(LIBFT) $(NAME)
		ar rcs $(NAME) $(OBJ)

$(LIBFT): 
		@if test -d "$(LIBFT_DIR)"; then \
		echo "Updating libft..."; git -C $(LIBFT_DIR) pull; else \
		git clone https://github.com/p-molnar/libft.git $(LIBFT_DIR); \
		fi
		make $(LIBFT) -C $(LIBFT_DIR)


 %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all 

.PHONY: all bonus clean fclean re