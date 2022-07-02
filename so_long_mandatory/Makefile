# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/21 05:55:16 by yer-retb          #+#    #+#              #
#    Updated: 2022/07/01 15:34:58 by yer-retb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = get_next_line.c get_next_line_utils.c so_long.c ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c \
		ft_moves.c so_long_utils.c ft_more_moves.c map.c

GCC = cc

NAME = so_long

all: $(NAME)

$(NAME): $(SRC)
	@$(GCC) $(SRC) -Wall -Werror -Wextra -lmlx -framework OpenGL -framework Appkit -o $(NAME) 
	@echo "\033[1;32m so_long is Ready"

clean: 
	@rm -f $(NAME)

fclean: clean
	@rm -f $(NAME)

re: fclean all
