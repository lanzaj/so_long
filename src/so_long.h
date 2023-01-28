/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:06:04 by jlanza            #+#    #+#             */
/*   Updated: 2023/01/28 17:35:09 by jlanza           ###   ########.fr       */
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
}				t_img;

typedef struct s_layer {
	t_img	front;
	t_img	back;
}				t_layer;

typedef struct s_xpm {
	void	*xpm;
	int		width;
	int		heigh;
}				t_xpm;

typedef struct s_floor {
	t_xpm	f;
}				t_floor;

typedef struct s_wall {
	t_xpm	up;
	t_xpm	down;
	t_xpm	left;
	t_xpm	right;
}				t_wall;

typedef struct s_player {
	t_xpm	player;
	int		x;
	int		y;
}				t_player;

typedef struct s_coin {
	t_img	c1;
}				t_coin;

typedef struct s_exit {
	t_xpm	open;
	t_xpm	closed;
}				t_exit;


typedef struct s_data {
	void		*mlx;
	void		*win;
	int			width;
	int			heigh;
	t_layer		layer;
	t_floor		floor;
	t_wall		wall;
	t_exit		exit;
	t_coin		coin;
	t_player	player;
}				t_data;

typedef struct s_so_long
{
	t_list	*garbage;
}				t_so_long;

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

#endif
