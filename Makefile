# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pmolnar <pmolnar@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2022/01/25 17:30:10 by pmolnar       #+#    #+#                  #
#    Updated: 2022/01/26 13:09:49 by pmolnar       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME 		:=	libftprintf.a 
SRC  		:=	ft_printf.c							\
				src/print_formatted_arg.c			\
				src/formatting.c					\
				src/parse.c							\
				src/parse.c							\
				src/populate_struct.c				\
				src/put.c							\
				utils/ft_printf_formatting_utils.c	\
				utils/ft_printf_utils.c	

HEADER_DIR	?=	headers

LIBFT_DIR 	?=	libft
LIBFT		?=	libft.a

CC 			=	gcc
CFLAGS 		?=	-Wall -Wextra -Werror -I $(HEADER_DIR)

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		make $(LIBFT) -C $(LIBFT_DIR)
		cp $(LIBFT_DIR)/$(LIBFT) .
		mv $(LIBFT) $(NAME)
		ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: all

clean:
	rm -f $(OBJ)

fclean: clean
	make fclean --directory=libft
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re norm
