# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rparodi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 11:05:05 by rparodi           #+#    #+#              #
#    Updated: 2023/12/23 17:35:10 by raphael          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
CC=clang
CFLAGS=-Wall -Wextra -Werror
RM=rm -f
LIBFT = ./libft/ft_strdup.c ./libft/ft_strlcpy.c ./libft/ft_strlen.c
SRC = ./src/ft_printf.c ./src/ft_put.c
OBJ = $(SRC:.c=.o)
OBJLibft = $(LIBFT:.c=.o)

GREEN = \033[32m
GREY = \033[0;90m
RED = \033[0;31m
GOLD = \033[38;5;220m
END = \033[0m

header:
		@printf '\n\n'
		@printf '$(GOLD)            *******     *****  ******* $(END)\n'
		@printf '$(GOLD)          ******        ***    ******* $(END)\n'
		@printf '$(GOLD)      *******                 ******* $(END)\n'
		@printf '$(GOLD)     ******                 ******* $(END)\n'
		@printf '$(GOLD)  *******                 ******* $(END)\n'
		@printf '$(GOLD) ********************   *******      * $(END)\n'
		@printf '$(GOLD) ********************   *******    *** $(END)\n'
		@printf '$(GOLD)              *******   ******* ****** $(END)\n'
		@printf '$(GOLD)              ******* $(END)\n'
		@printf '$(GOLD)              ******* $(END)\n\n'
		@printf '$(GREY)                                      Made by rparodi$(END)\n\n\n'

$(NAME): $(OBJ) $(OBJLibft)
		@printf '$(GREY) Compiling $(END)$(GOLD)$(NAME)$(END)\n'
		@ar rc $(NAME) $(OBJ) $(OBJLibft)
		@ranlib $(NAME)

%.o: %.c
		@printf '$(GREY) Compiling $(END)$(GREEN)$<$(END)\n'
		@$(CC) -I. -o $@ -c $? $(CFLAGS)

all: header $(NAME)
		@printf '\n$(GREY) Compilation $(GREEN)Done\n'

dev: all bonus clean

clean:
		@printf '$(GREY) Removing $(END)$(RED)Object$(END)\n'
		@$(RM) $(OBJ) $(OBJLibft)

fclean: clean
		@printf '$(GREY) Removing $(END)$(RED)Program$(END)\n'
		@$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re dev header
