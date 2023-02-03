/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:06:04 by jlanza            #+#    #+#             */
/*   Updated: 2023/02/04 00:38:22 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//# include <sys/types.h>
//# include <sys/stat.h>

/* include for open */
# include <fcntl.h>

/* include math lib*/
# include <math.h>

/* include libft */
# include "../libft/libft.h"

/* include minilix */
# include "../minilibx-linux/mlx.h"

# define RES_X 1080
# define RES_Y 720

# define MINI_LOOP 30
# define LONG_LOOP 40

# define SPEED_CARDINAL 80
# define SPEED_DIAGONAL 52

typedef struct s_coord {
	int	x;
	int	y;
}				t_coord;

typedef struct s_img {
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct s_layer {
	t_img	front;
	t_img	back;
	t_img	tmp;
	t_img	render;
}				t_layer;

typedef struct s_floor {
	t_img	f1;
	t_img	f2;
	t_img	f3;
	t_img	f4;
	t_img	f5;
	t_img	f6;
	t_img	f7;
	t_img	f8;
	t_img	start;
}				t_floor;

typedef struct s_wall {
	t_img	mid;
	t_img	mid1;
	t_img	mid3;
	t_img	mid6;
	t_img	mid61;
	t_img	mid7;
	t_img	mid8;
	t_img	top_up;
	t_img	top_right;
	t_img	top_left;
	t_img	side_left;
	t_img	side_down_l;
	t_img	side_down_r;
	t_img	side_top_l;
	t_img	side_top_r;
	t_img	side_right;
	t_img	corner_rl;
	t_img	corner_right;
	t_img	corner_left;
	t_img	solo_front;
	t_img	solo_top;
	t_img	solo_corner;
	t_img	bottom;
	t_img	column_top;
	t_img	column_mid;
	t_img	column_base;
	t_img	front_l;
	t_img	front_r;
}				t_wall;

typedef struct s_sprite {
	t_img	idle_0;
	t_img	idle_1;
	t_img	idle_2;
	t_img	idle_3;
	t_img	run_0;
	t_img	run_1;
	t_img	run_2;
	t_img	run_3;
}				t_sprite;

typedef struct s_player {
	t_sprite	l;
	t_sprite	r;
	t_coord		coord;
}				t_player;

typedef struct s_coin {
	t_img	c0;
	t_img	c1;
	t_img	c2;
	t_img	c3;
}				t_coin;

typedef struct s_exit {
	t_img	exit_layer;
}				t_exit;

typedef struct s_way {
	char	up;
	char	left;
	char	right;
	char	down;
	char	dir;
}				t_way;

typedef struct s_map {
	char	**ptr;
	int		width;
	int		height;
	t_coord	tile_coord;
}				t_map;

typedef struct s_data {
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	int			last_pixel_offset;
	int			frame;
	int			long_frame;
	int			number_of_mouvements;
	int			nbr_of_collectible;
	t_map		map;
	t_coord		coord;
	t_way		way;
	t_layer		layer;
	t_floor		floor;
	t_wall		wall;
	t_exit		exit;
	t_coin		coin;
	t_player	player;
}				t_data;

			/* COUNT IN MAP */
int		count_number_of_lines(char **map);
int		count_char_in_map(char **map, char c);

			/* CHECK */
void	check_map(char **map);
int		check_extension(char *path);
void	check_if_enclosed_in_walls(char **map);
void	check_map_flood(char **map);

			/* MAP ERROR */
void	parse_map_error(int return_value);
void	check_map_error(int return_value, char **map);

			/* Map */
char	**import_map(char *path);
char	**dup_map(char **map);
char	**free_map(char **tab);
void	print_map(char **map);

			/* GUI */
void	new_layer(t_data *data, t_img *layer);
void	big_new_layer(t_data *data, t_img *layer);
void	import_imgs(t_data *data);

int		get_color(t_img *xpm, int x, int y);
void	pixel_put_tmp_layer(t_data *data, int x, int y, int color);
void	background_put_tmp(t_data *data, int color);
void	background_put_back(t_data *data, int color);
void	background_put_front(t_data *data, int color);
void	put_img_to_tmp(t_data *data, t_img *xpm, int x, int y);
void	put_img_to_back(t_data *data, t_img *xpm, int x, int y);
void	put_img_to_front(t_data *data, t_img *xpm, int x, int y);
void	my_mlx_put_tmp_to_render(t_data *data);
void	draw_mini_map(t_data *data, t_img *xpm, t_coord player);
void	draw_mini_map_tlayer(t_data *data, t_img *xpm, t_coord player);
void	put_player(t_data *d, t_coord coord, t_sprite p, int frame);
void	put_coins(t_data *data, t_coord coord);
void	put_exit_to_map(t_data *data);

			/* Generating map */
void	generate_minimap(t_data *data);
void	draw_wall(t_data *data, int x, int y);
void	draw_floor(t_data *data, int x, int y);

void	pixel_put_tmp_layer(t_data *data, int x, int y, int color);
void	pixel_put_back_layer(t_data *data, int x, int y, int color);

int		get_random(void);
int		get_n_random(int n);

int		close_window(t_data *data);

			/* Game */
void	init_mlx(t_data *data);
int		game_init(t_data *data);
void	init_data(t_data *data);
void	get_starting_pos(t_data *data);
int		game_loop(t_data *data);
int		key_press(int keycode, void *data);
int		key_release(int keycode, void *data);
void	update_x_y(t_data *data, t_way *way, t_coord *coord);
void	update_map_x_y(t_data *data);
void	event_player(t_data *data, int x, int y);
int		from_player_x_to_map_tile_x(t_data *data, int x);
int		from_player_y_to_map_tile_y(t_data *data, int y);
char	from_player_pos_to_map_char(t_data *data, int x, int y);
char	get_type_tile_player(t_data *data, t_map *map, int x, int y);
char	get_type_tile_under_player(t_data *data, t_map *map, int x, int y);
char	get_type_tile(t_map *map, int x, int y);

#endif
