# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 15:24:20 by jlanza            #+#    #+#              #
#    Updated: 2023/01/29 16:43:19 by jlanza           ###   ########.fr        #
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
		src/map/count_in_map.c \
		src/map/dup_map.c \
		src/gui/my_mlx_function.c

LIBFT = libft/libft.a
LIBMLX = minilibx-linux/libmlx.a
LIBMLX_LINUX = minilibx-linux/libmlx_Linux.a
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
	$(MAKE) -C ./minilibx-linux
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(LIBMLX) $(LIBMLX_LINUX) -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

all: $(NAME)

clean:
	$(RM) *.o */*.o */*/*.o
	$(MAKE) fclean -C ./libft
	$(MAKE) clean -C ./minilibx-linux

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
