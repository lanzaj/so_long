# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 15:24:20 by jlanza            #+#    #+#              #
#    Updated: 2024/03/22 15:09:01 by jlanza           ###   ########.fr        #
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
		src/gui/my_mlx_function.c \
		src/gui/get_random.c \
		src/gui/init_layer.c \
		src/gui/import_images.c \
		src/gui/import_images2.c \
		src/gui/close_windows.c \
		src/gui/draw_mini_map.c \
		src/gui/put_player.c \
		src/gui/put_coin.c \
		src/gui/put_exit.c \
		src/gui/pixel_put.c \
		src/gui/get_color.c \
		src/gui/put_background.c \
		src/gui/put_img_to_layer.c \
		src/gui/put_nbr_of_mouvement.c \
		src/gui/put_monsters.c \
		src/gui/display_endscreen.c \
		src/generate_map/draw_wall.c \
		src/generate_map/draw_floor.c \
		src/generate_map/is_tile_in_charset.c \
		src/generate_map/is_wall.c \
		src/generate_map/is_wall2.c \
		src/generate_map/draw_upper_wall.c \
		src/generate_map/draw_lower_wall.c \
		src/generate_map/draw_right_left_column_wall.c \
		src/generate_map/generate_minimap.c \
		src/game/key_event.c \
		src/game/game_init.c \
		src/game/game_loop.c \
		src/game/update_x_y.c \
		src/game/init_data.c \
		src/game/from_player_pos_to_map_char.c \
		src/game/get_type_tile.c \
		src/game/get_starting_pos.c \
		src/game/update_map_x_y.c \
		src/game/event_player.c \
		src/game/place_monsters.c

LIBFT = libft/libft.a
LIBMLX = minilibx-linux/libmlx.a
LIBMLX_LINUX = minilibx-linux/libmlx_Linux.a
OBJ = ${SRC:.c=.o}

NAME = so_long
CFLAGS = -Wall -Wextra -Werror -O3 -march=native -flto
CC = cc
RM = rm -f
HEADER = src/so_long.h

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
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

bonus: all

.PHONY: all clean fclean re all bonus
