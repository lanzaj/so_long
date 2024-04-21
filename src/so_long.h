/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:06:04 by jlanza            #+#    #+#             */
/*   Updated: 2024/04/21 17:46:28 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <limits.h>
# include <sys/time.h>
# include <X11/Xlib.h>
# include <X11/Xutil.h>
# include <X11/Xatom.h>

# define SPEED_DIAGONAL 0.70710678

# define MINI_LOOP 500000
# define LONG_LOOP 1000000

// # define MLX_MAX_EVENT LASTEvent

// typedef struct	s_event_list
// {
// 	int		mask;
// 	int		(*hook)();
// 	void	*param;
// }				t_event_list;

// typedef struct	s_win_list
// {
// 	Window				window;
// 	GC					gc;
// 	struct s_win_list	*next;
// 	int					(*mouse_hook)();
// 	int					(*key_hook)();
// 	int					(*expose_hook)();
// 	void				*mouse_param;
// 	void				*key_param;
// 	void				*expose_param;
// 	t_event_list		hooks[MLX_MAX_EVENT];
// }				t_win_list;

// typedef struct	s_xvar
// {
// 	Display		*display;
// 	Window		root;
// 	int			screen;
// 	int			depth;
// 	Visual		*visual;
// 	Colormap	cmap;
// 	int			private_cmap;
// 	t_win_list	*win_list;
// 	int			(*loop_hook)();
// 	void		*loop_param;
// 	int			use_xshm;
// 	int			pshm_format;
// 	int			do_flush;
// 	int			decrgb[6];
// 	Atom		wm_delete_window;
// 	Atom		wm_protocols;
// 	int 		end_loop;
// }				t_xvar;

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

typedef struct s_way {
	char	up;
	char	left;
	char	right;
	char	down;
	char	dir;
}				t_way;

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

typedef struct s_monster {
	t_sprite	l;
	t_sprite	r;
	t_coord		coord;
	int			dir;
	int			moving;
}				t_monster;

typedef struct s_coin {
	t_img	c0;
	t_img	c1;
	t_img	c2;
	t_img	c3;
}				t_coin;

typedef struct s_exit {
	t_img	exit_layer;
}				t_exit;

typedef struct s_digit {
	t_img	d_0;
	t_img	d_1;
	t_img	d_2;
	t_img	d_3;
	t_img	d_4;
	t_img	d_5;
	t_img	d_6;
	t_img	d_7;
	t_img	d_8;
	t_img	d_9;
}				t_digit;

typedef struct s_map {
	char	**ptr;
	int		width;
	int		height;
	t_coord	tile_coord;
}				t_map;

typedef struct s_end {
	t_img	win;
	t_img	win2;
	t_img	lose;
	t_img	lose2;
	int		won;
	int		lost;
}				t_end;

typedef struct s_data {
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	int			last_pixel_offset;
	int			speed;
	int			number_of_mouvements;
	int			nbr_of_collectible;
	void		*img_tab[124];
	t_end		end;
	t_map		map;
	t_coord		coord;
	t_way		way;
	t_layer		layer;
	t_floor		floor;
	t_wall		wall;
	t_exit		exit;
	t_coin		coin;
	t_digit		digit;
	t_player	player;
	t_monster	demon;
	t_monster	orc;
	t_monster	undead;
	unsigned long	frame;
	unsigned long	long_frame;
	struct timeval	last_time;
	struct timeval	t0;
}				t_data;

			/* COUNT IN MAP */
int				count_number_of_lines(char **map);
int				count_char_in_map(char **map, char c);

			/* CHECK */
void			check_map(char **map);
int				check_extension(char *path);
void			check_if_enclosed_in_walls(char **map);
void			check_map_flood(char **map);

			/* MAP ERROR */
void			parse_map_error(int return_value);
void			check_map_error(int return_value, char **map);
void			lst_to_tab_error(t_list *lst, char **map, int fd);
void			lst_to_tab_calloc_fail(t_list *lst, int fd);

			/* Map */
char			**import_map(char *path);
char			**dup_map(char **map);
char			**free_map(char **tab);
void			print_map(char **map);

			/* graphic */
void			new_layer(t_data *data, t_img *layer);
void			import_imgs(t_data *data);
void			import_img(t_data *data, t_img *xpm, char *path);
void			import_imgs_part6(t_data *data);

int				get_color(t_img *xpm, int x, int y);
void			pixel_put_tmp_layer(t_data *data, int x, int y, int color);
void			background_put_tmp(t_data *data, int color);
void			background_put_back(t_data *data, int color);
void			banner_put_tmp(t_data *data, int color);
void			put_img_to_tmp(t_data *data, t_img *xpm, int x, int y);
void			put_img_to_fullscreen_tmp(t_data *data, t_img *xpm);
void			put_img_to_back(t_data *data, t_img *xpm, int x, int y);
void			put_img_to_front(t_data *data, t_img *xpm, int x, int y);
void			draw_mini_map(t_data *data, t_img *xpm, t_coord player);
void			draw_mini_map_tlayer(t_data *data, t_img *xpm, t_coord player);

void			put_player(t_data *d);
void			put_coins(t_data *data, t_coord coord);
void			put_exit_to_map(t_data *data);
void			put_nbr_of_mouvement(t_data *data, int n);
void			put_entities(t_data *data);

void			pixel_put_front_layer(t_data *data, int x, int y, int color);
void			pixel_put_back_layer(t_data *data, int x, int y, int color);
void			pixel_put_tmp_layer(t_data *data, int x, int y, int color);

unsigned char	get_t(int trgb);
int				get_color(t_img *xpm, int x, int y);
void			square_put_tmp(t_data *data, int x, int y, int color);
void			display_endscreen(t_data *data);

			/* Generating map */
void			generate_minimap(t_data *data);
void			draw_wall(t_data *data, int x, int y);
void			draw_floor(t_data *data, int x, int y);
void			draw_upper_wall_corner_left_front(t_data *data, int x, int y);
void			draw_upper_wall_corner_right_front(t_data *data, int x, int y);
void			draw_random_upper_wall(t_data *data, int x, int y);
void			draw_lower_wall_corner_left_continuing_down(t_data *data,
					int x, int y);
void			draw_lower_wall_corner_right_continuing_down(t_data *data,
					int x, int y);
void			draw_lower_wall_right_corner(t_data *data, int x, int y);
void			draw_lower_wall_left_corner(t_data *data, int x, int y);
void			draw_random_lower_wall(t_data *data, int x, int y);
void			draw_column(t_data *data, int x, int y);
void			draw_left_wall(t_data *data, int x, int y);
void			draw_right_wall(t_data *data, int x, int y);
int				is_tile_in_charset(t_data *data, char *charset, int x, int y);
void			pixel_put_tmp_layer(t_data *data, int x, int y, int color);
void			pixel_put_back_layer(t_data *data, int x, int y, int color);
int				is_left_wall(t_data *data, int x, int y);
int				is_right_wall(t_data *data, int x, int y);
int				is_upper_wall(t_data *data, int x, int y);
int				is_lower_wall(t_data *data, int x, int y);
int				is_side_wall(t_data *data, int x, int y);
int				is_column(t_data *data, int x, int y);
int				is_left_corner(t_data *data, int x, int y);
int				is_right_corner(t_data *data, int x, int y);
int				is_wall_continuing_down(t_data *data, int x, int y);
void			place_monsters(t_data *data);
int				get_random(void);
int				get_n_random(int n);

			/* Game */
void			init_mlx(t_data *data);
int				game_init(t_data *data);
void			init_data(t_data *data);
void			get_starting_pos(t_data *data);
int				game_loop(t_data *data);
int				key_press(int keycode, void *data);
int				key_release(int keycode, void *data);
void			update_x_y(t_data *data, t_way *way, t_coord *coord);
void			update_map_x_y(t_data *data);
void			event_player(t_data *data, int x, int y);
void			event_monsters(t_data *data);
int				from_player_x_to_map_tile_x(t_data *data, int x);
int				from_player_y_to_map_tile_y(t_data *data, int y);
char			from_player_pos_to_map_char(t_data *data, int x, int y);
char			get_type_tile_player(t_data *data, t_map *map, int x, int y);
char			get_type_tile_under_player(t_data *data,
					t_map *map, int x, int y);
char			get_type_tile(t_map *map, int x, int y);
int				close_window(t_data *data);
int				close_window_error(t_data *data);

#endif
