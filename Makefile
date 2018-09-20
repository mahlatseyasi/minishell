# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkhoza <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/06 09:45:43 by mkhoza            #+#    #+#              #
#    Updated: 2018/09/19 16:19:29 by mkhoza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
LIB = libft_mini

CFLAGS = -Wall -Wextra -Werror

SRC = ft_env.c echo_command.c cd_command.c ft_emacs.c i_val.c

OUTPUT = ft_env.o echo_command.o cd_command.o ft_emacs.o i_val.o

$(NAME):
	@make -C ./libft
	@gcc $(CFLAGS) -c $(SRC) -I ./
	@ar -rc $(LIB) $(OUTPUT) ./libft/*.o
	@ranlib $(LIB)
	@gcc minishell.c $(LIB) -o $(NAME)
	@echo "\033[32mminishell created\033[0m"

all: $(NAME)

clean:
	@rm -f $(OUTPUT)
	@make -C ./libft clean

fclean: clean
	@rm -f $(NAME) $(LIB)
	@make -C ./libft fclean
	@echo "\033[31mminishell successful destroyed\033[0m"
re: fclean all

.PHONY: all fclean clean re
