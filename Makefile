# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 15:24:20 by jlanza            #+#    #+#              #
#    Updated: 2023/01/25 16:29:13 by jlanza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	src/main.c \
		src/map/import_map.c \
		src/map/free_map.c \
		src/map/map_error.c \
		src/map/check_extension.c \
		src/map/check_map.c \
		src/map/check_map_flood.c \
		src/map/check_if_enclosed_in_walls.c \
		src/map/print_map.c \
		src/map/ft_map.c \
		src/map/dup_map.c

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
	$(RM) *.o */*.o */*/*.o
	$(MAKE) fclean -C ./libft

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
