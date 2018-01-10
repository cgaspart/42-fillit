# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/11 11:11:37 by cgaspart          #+#    #+#              #
#    Updated: 2018/01/05 09:32:51 by cgaspart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
OBJ_PATH = obj
LDFLAGS = -L./libft
LDLIBS = -lft
CFLAGS = -Werror -Wall -Wextra
CC = clang
SRC_NAME = main.c\
		   ft_blocks_analyzer.c\
		   ft_lst_tab.c\
		   ft_reader.c\
		   ft_verif.c\
		   ft_htag_count.c\
		   ft_mapgen.c\
		   ft_solve.c
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(OBJ_PATH)/%.o: %.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -fv $(OBJ)
	make -C libft clean
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	rm -fv $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all, clean, fclean, re
