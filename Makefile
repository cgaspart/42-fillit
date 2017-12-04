# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 10:42:03 by cgaspart          #+#    #+#              #
#    Updated: 2017/11/30 18:18:58 by cgaspart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
LIB = libft.a
FLAG = -Wall -Wextra -Werror
OPTION = -c
SRC =	main.c ft_verif.c ft_reader.c ft_blocks_analyzer.c ft_htag_count.c ft_mapgen.c ft_lst_tab.c ft_solve.c

OBJETS = $(SRCLIB:.c=.o)

all: $(NAME)

$(NAME): $(LIB)
	gcc -o $(NAME) $(FLAG) $(SRC) -L./libft -lft

$(LIB):
	make -C libft re

clean:
	make -C libft clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft fclean

re: fclean all
