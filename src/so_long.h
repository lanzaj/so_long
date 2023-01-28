/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:06:04 by jlanza            #+#    #+#             */
/*   Updated: 2023/01/28 22:59:20 by jlanza           ###   ########.fr       */
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
	t_img	f;
}				t_floor;

typedef struct s_wall {
	t_img	up;
	t_img	down;
	t_img	left;
	t_img	right;
}				t_wall;

typedef struct s_player {
	t_img	player;
	int		x;
	int		y;
}				t_player;

typedef struct s_coin {
	t_img	c1;
}				t_coin;

typedef struct s_exit {
	t_img	open;
	t_img	closed;
}				t_exit;


typedef struct s_data {
	void		*mlx;
	void		*win;
	int			width;
	int			heigh;
	int			last_pixel_offset;
	char		**map;
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

			/* gui */
void	my_mlx_background_put(t_data *data, int color);
void	my_mlx_put_img_to_tmp_layer(t_data *data, t_img *xpm, int x, int y);
void	my_mlx_put_tmp_to_render(t_data *data);

#endif
