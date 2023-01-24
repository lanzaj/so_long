# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 15:24:20 by jlanza            #+#    #+#              #
#    Updated: 2023/01/24 15:02:39 by jlanza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	src/main.c

LIBFT = ./libft/libft.a
OBJ = ${SRC:.c=.o}

NAME = so_long
CFLAGS = -Wall -Wextra -Werror -g3
CC = cc
RM = rm -f
HEADER = src/so_long.h

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ) $(HEADER)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) libft/libft.a

all: $(NAME)

clean:
	$(RM) *.o */*.o
	$(MAKE) fclean -C ./libft

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
