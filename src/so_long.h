/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:06:04 by jlanza            #+#    #+#             */
/*   Updated: 2023/02/01 05:03:33 by jlanza           ###   ########.fr       */
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

# define MINI_LOOP 30
# define LONG_LOOP 40

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
	t_img	test;
	t_img	tmp;
	t_img	render;
}				t_layer;

typedef struct s_floor {
	t_img	f;
}				t_floor;

typedef struct s_wall {
	t_img	up;
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
	t_img	c1;
}				t_coin;

typedef struct s_exit {
	t_img	open;
	t_img	closed;
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
int		get_color(t_img *xpm, int x, int y);
void	pixel_put_tmp_layer(t_data *data, int x, int y, int color);
void	background_put_tmp(t_data *data, int color);
void	background_put_back(t_data *data, int color);
void	background_put_front(t_data *data, int color);
void	put_img_to_tmp(t_data *data, t_img *xpm, int x, int y);
void	put_img_to_back(t_data *data, t_img *xpm, int x, int y);
void	put_img_to_front(t_data *data, t_img *xpm, int x, int y);
void	my_mlx_put_tmp_to_render(t_data *data);

			/* Draw wall */
void	draw_wall(t_data *data, int x, int y);
void	draw_floor(t_data *data, int x, int y);

void	pixel_put_tmp_layer(t_data *data, int x, int y, int color);
void	pixel_put_back_layer(t_data *data, int x, int y, int color);

#endif
