# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rparodi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 11:05:05 by rparodi           #+#    #+#              #
#    Updated: 2023/11/16 15:14:07 by rparodi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
CC=cc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f
LIBFT = ./libft/ft_strdup.c ./libft/ft_strlcpy.c ./libft/ft_strlen.c
SRC = ./src/ft_printf.c ./src/ft_put.c
OBJ = $(SRC:.c=.o)
OBJLibft = $(LIBFT:.c=.o)

$(NAME): $(OBJ) $(OBJLibft)
		ar rc $(NAME) $(OBJ) $(OBJLibft)
		ranlib $(NAME)

%.o: %.c
		$(CC) -I. -o $@ -c $? $(CFLAGS)

all: $(NAME)

bonus: $(OBJ) $(OBJLibft)
		ar rc $(NAME) $(OBJ) $(OBJLibft)
		ranlib $(NAME)


dev: all bonus clean

clean:
		$(RM) $(OBJ) $(OBJLibft)

fclean: clean
		$(RM) $(NAME)

re: fclean all bonus

.PHONY: clean clean
