/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:05:56 by jlanza            #+#    #+#             */
/*   Updated: 2023/02/02 22:22:27 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// LISTE DE TRUCS A FAIRE :
// - improve top wall texture
// - importer et afficher les variantes
// - ajouter collectible
// - ajouter sortie
// - ajouter enemies
// - ajouter UI

void	new_layer(t_data *data, t_img *layer)
{
	layer->width = data->width;
	layer->height = data->height;
	layer->img = mlx_new_image(data->mlx, layer->width, layer->height);
	layer->addr = mlx_get_data_addr(layer->img, &(layer->bits_per_pixel),
			&(layer->line_length),
			&(layer->endian));
}

void	big_new_layer(t_data *data, t_img *layer)
{
	layer->width = 1024;
	layer->height = 1024;
	layer->img = mlx_new_image(data->mlx, layer->width, layer->height);
	layer->addr = mlx_get_data_addr(layer->img, &(layer->bits_per_pixel),
			&(layer->line_length),
			&(layer->endian));
}

void	import_img(t_data *data, t_img *xpm, char *path)
{
	xpm->img = mlx_xpm_file_to_image(data->mlx,
			path, &(xpm->width), &(xpm->height));
	xpm->addr = mlx_get_data_addr(xpm->img, &(xpm->bits_per_pixel),
			&(xpm->line_length), &(xpm->endian));
}

void	import_imgs(t_data *data)
{
	import_img(data, &(data->layer.front), "./img/empty.xpm");
	new_layer(data, &(data->layer.back));
	new_layer(data, &(data->layer.tmp));
	new_layer(data, &(data->layer.render));
	import_img(data, &(data->floor.f1), "./img/floor_1.xpm");
	import_img(data, &(data->floor.f2), "./img/floor_2.xpm");
	import_img(data, &(data->floor.f3), "./img/floor_3.xpm");
	import_img(data, &(data->floor.f4), "./img/floor_4.xpm");
	import_img(data, &(data->floor.f5), "./img/floor_5.xpm");
	import_img(data, &(data->floor.f6), "./img/floor_6.xpm");
	import_img(data, &(data->floor.f7), "./img/floor_7.xpm");
	import_img(data, &(data->floor.f8), "./img/floor_8.xpm");
	import_img(data, &(data->wall.mid), "./img/wall_mid.xpm");
	import_img(data, &(data->wall.mid1), "./img/wall_mid_1.xpm");
	import_img(data, &(data->wall.mid2), "./img/wall_mid_2.xpm");
	import_img(data, &(data->wall.mid3), "./img/wall_mid_3.xpm");
	import_img(data, &(data->wall.mid4), "./img/wall_mid_4.xpm");
	import_img(data, &(data->wall.mid5), "./img/wall_mid_5.xpm");
	import_img(data, &(data->wall.mid51), "./img/wall_mid_51.xpm");
	import_img(data, &(data->wall.mid52), "./img/wall_mid_52.xpm");
	import_img(data, &(data->wall.mid6), "./img/wall_mid_6.xpm");
	import_img(data, &(data->wall.mid61), "./img/wall_mid_61.xpm");
	import_img(data, &(data->wall.mid7), "./img/wall_mid_7.xpm");
	import_img(data, &(data->wall.mid8), "./img/wall_mid_8.xpm");
	import_img(data, &(data->wall.side_left), "./img/wall_side_mid_left.xpm");
	import_img(data, &(data->wall.side_right), "./img/wall_side_mid_right.xpm");
	import_img(data, &(data->wall.side_down_l), "./img/wall_side_l.xpm");
	import_img(data, &(data->wall.side_down_r), "./img/wall_side_r.xpm");
	import_img(data, &(data->wall.side_top_l), "./img/wall_side_top_l.xpm");
	import_img(data, &(data->wall.side_top_r), "./img/wall_side_top_r.xpm");
	import_img(data, &(data->wall.corner_rl), "./img/wall_corner_r_l.xpm");
	import_img(data, &(data->wall.solo_front), "./img/wall_solo_front.xpm");
	import_img(data, &(data->wall.solo_top), "./img/wall_top_solo.xpm");
	import_img(data, &(data->wall.bottom), "./img/wall_top_solo_bottom.xpm");
	import_img(data, &(data->wall.solo_corner), "./img/solo_corner.xpm");
	import_img(data, &(data->wall.top_up), "./img/wall_top_mid.xpm");
	import_img(data, &(data->wall.column_top), "./img/column_top.xpm");
	import_img(data, &(data->wall.column_mid), "./img/column_mid.xpm");
	import_img(data, &(data->wall.column_base), "./img/column_base.xpm");
	import_img(data, &(data->wall.front_l), "./img/wall_corner_front_left.xpm");
	import_img(data, &(data->wall.front_r), "./img/wall_corner_front_righ.xpm");
	import_img(data, &(data->wall.top_right), "./img/wall_top_right.xpm");
	import_img(data, &(data->wall.top_left), "./img/wall_top_left.xpm");
	import_img(data, &(data->wall.corner_right), "./img/wall_corner_right.xpm");
	import_img(data, &(data->wall.corner_left), "./img/wall_corner_left.xpm");
	import_img(data, &(data->player.r.idle_0), "./img/64_knight_idle_r0.xpm");
	import_img(data, &(data->player.r.idle_1), "./img/64_knight_idle_r1.xpm");
	import_img(data, &(data->player.r.idle_2), "./img/64_knight_idle_r2.xpm");
	import_img(data, &(data->player.r.idle_3), "./img/64_knight_idle_r3.xpm");
	import_img(data, &(data->player.r.run_0), "./img/64_knight_run_r0.xpm");
	import_img(data, &(data->player.r.run_1), "./img/64_knight_run_r1.xpm");
	import_img(data, &(data->player.r.run_2), "./img/64_knight_run_r2.xpm");
	import_img(data, &(data->player.r.run_3), "./img/64_knight_run_r3.xpm");
	import_img(data, &(data->player.l.idle_0), "./img/64_knight_idle_l0.xpm");
	import_img(data, &(data->player.l.idle_1), "./img/64_knight_idle_l1.xpm");
	import_img(data, &(data->player.l.idle_2), "./img/64_knight_idle_l2.xpm");
	import_img(data, &(data->player.l.idle_3), "./img/64_knight_idle_l3.xpm");
	import_img(data, &(data->player.l.run_0), "./img/64_knight_run_l0.xpm");
	import_img(data, &(data->player.l.run_1), "./img/64_knight_run_l1.xpm");
	import_img(data, &(data->player.l.run_2), "./img/64_knight_run_l2.xpm");
	import_img(data, &(data->player.l.run_3), "./img/64_knight_run_l3.xpm");
}

void	get_starting_pos(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.height)
	{
		j = 0;
		while (j < data->map.width)
		{
			if (data->map.ptr[i][j] == 'P')
			{
				data->coord.x = 10 * (j * 64 - data->player.coord.x + 64);
				data->coord.y = 10 * (i * 64 - data->player.coord.y);
				return ;
			}
			j++;
		}
		i++;
	}
}

char	get_type_tile(t_data *data, t_map *map, int x, int y)
{
	int	map_x;
	int	map_xr;
	int	map_xl;
	int	map_y;

	map_x = (x / 10 + data->width / 2) / 64 - 1;
	map_xr = (x / 10 + 20 + data->width / 2) / 64 - 1;
	map_xl = (x / 10 - 20 + data->width / 2) / 64 - 1;
	map_y = (y / 10 + 30 + data->height / 2) / 64 - 1;
	if (map_x < 0 || map_x >= map->width)
		return ('1');
	if (map_y < 0 || map_y >= map->height)
		return ('1');
	if (map->ptr[map_y][map_xr] == '1' || '1' == map->ptr[map_y][map_xl])
		return ('1');
	return (map->ptr[map_y][map_x]);
}

void	update_x_y(t_data *data, t_way *way, t_coord *coord)
{
	int	move;

	move = 0;
	if (way->up != way->down && way->right != way->left)
		move = SPEED_DIAG;
	else if (way->up != way->down || way->right != way->left)
		move = SPEED_CARD;
	if (way->up && !(way->down) && get_type_tile(data,
			&(data->map), coord->x, coord->y - move - 200) != '1')
			coord->y += -move;
	if (!(way->up) && way->down && get_type_tile(data,
			&(data->map), coord->x, coord->y + move + 8) != '1')
			coord->y += move;
	if (way->left && !(way->right) && get_type_tile(data,
			&(data->map), coord->x - move, coord->y) != '1'
		&& get_type_tile(data, &(data->map), coord->x - move, coord->y - 200) != '1')
	{
		coord->x += -move;
		way->dir = 0;
	}
	if (!(way->left) && way->right && get_type_tile(data,
			&(data->map), coord->x + move, coord->y) != '1'
		&& get_type_tile(data, &(data->map), coord->x + move, coord->y - 200) != '1')
	{
		coord->x += move;
		way->dir = 1;
	}
}

void	generate_minimap(t_data *data)
{
	char	**map;
	t_coord	tile;

	map = data->map.ptr;
	background_put_back(data, 0x00232323);
	tile.y = 0;
	while (tile.y < data->map.height)
	{
		tile.x = 0;
		while (tile.x < data->map.width)
		{
			if ((tile.x * 16) < data->width + 16
				&& (tile.y * 16) < data->height + 16
				&& tile.x * 16 > -80
				&& tile.y * 16 > -80)
			{
				if (ft_strchr("0PEC", map[tile.y][tile.x]))
					draw_floor(data, tile.x, tile.y);
				if (map[tile.y][tile.x] == '1')
					draw_wall(data, tile.x, tile.y);
			}
			tile.x++;
		}
		tile.y++;
	}
}

void	draw_mini_map(t_data *data, t_img *xpm, t_coord player)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->layer.tmp.height)
	{
		x = 0;
		while (x < data->layer.tmp.width)
		{
			pixel_put_tmp_layer(data, x, y,
				get_color(xpm, (x + player.x / 10) / 4,
					(y + player.y / 10) / 4));
			x++;
		}
		y++;
	}
}

void	draw_mini_map_tlayer(t_data *data, t_img *xpm, t_coord player)
{
	int	x;
	int	y;

	y = data->layer.tmp.height / 2 + 8;
	while (y < data->layer.tmp.height / 2 + 32)
	{
		x = data->layer.tmp.width / 2 - 30;
		while (x < data->layer.tmp.width / 2 + 30)
		{
			pixel_put_tmp_layer(data, x, y,
				get_color(xpm, (x + player.x / 10) / 4,
					(y + player.y / 10) / 4));
			x++;
		}
		y++;
	}
}

void	put_player(t_data *d, t_coord coord, t_sprite p, int frame)
{
	if (d->way.up != d->way.down || d->way.right != d->way.left)
	{
		if (frame < MINI_LOOP / 4)
			put_img_to_tmp(d, &(p.run_0), coord.x, coord.y);
		else if (frame < MINI_LOOP / 2)
			put_img_to_tmp(d, &(p.run_1), coord.x, coord.y);
		else if (frame < MINI_LOOP * 3 / 4)
			put_img_to_tmp(d, &(p.run_2), coord.x, coord.y);
		else
			put_img_to_tmp(d, &(p.run_3), coord.x, coord.y);
	}
	else
	{
		if (d->long_frame < LONG_LOOP / 4)
			put_img_to_tmp(d, &(p.idle_0), coord.x, coord.y);
		else if (d->long_frame < LONG_LOOP / 2)
			put_img_to_tmp(d, &(p.idle_1), coord.x, coord.y);
		else if (d->long_frame < LONG_LOOP * 3 / 4)
			put_img_to_tmp(d, &(p.idle_2), coord.x, coord.y);
		else
			put_img_to_tmp(d, &(p.idle_3), coord.x, coord.y);
	}
}

void	square_put_tmp(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			pixel_put_tmp_layer(data, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	update_map_x_y(t_data *data)
{
	if (data->map.tile_coord.x != (data->coord.x / 10
			+ data->width / 2) / 64 - 1)
	{
		data->map.tile_coord.x = (data->coord.x / 10
				+ data->width / 2) / 64 - 1;
		data->number_of_mouvements++;
		ft_printf("number of mouvements: %d\n", data->number_of_mouvements);
	}
	if (data->map.tile_coord.y != (data->coord.y / 10
			+ 30 + data->height / 2) / 64 - 1)
	{
		data->map.tile_coord.y = (data->coord.y / 10
				+ 30 + data->height / 2) / 64 - 1;
		data->number_of_mouvements++;
		ft_printf("number of mouvements: %d\n", data->number_of_mouvements);
	}
}

int	game(t_data *data)
{
	data->frame++;
	if ((data->frame) > MINI_LOOP)
		data->frame = 0;
	data->long_frame++;
	if ((data->long_frame) > LONG_LOOP)
		data->long_frame = 0;
	//ft_memcpy(data->layer.tmp.addr, data->layer.back.addr,
	//	data->last_pixel_offset);
	//draw_map(data, data->coord);
	//draw_mini_map(data, &(data->layer.test), data->coord);

	//generate_minimap(data);
	//my_mlx_put_tmp_to_render(data);

	draw_mini_map(data, &(data->layer.back), data->coord);
	//draw_mini_map(data, &(data->layer.front), data->coord);

	if (data->way.dir)
		put_player(data, data->player.coord, data->player.r, data->frame);
	else
		put_player(data, data->player.coord, data->player.l, data->frame);

	draw_mini_map_tlayer(data, &(data->layer.front), data->coord);

	//put_img_to_tmp(data, &(data->layer.back), 1, 1);

	// point qui affiche le centre du perso pixel_put_tmp_layer(data, data->player.coord.x + 32, data->player.coord.y + 112, 0x00FF0000);

	//ft_memcpy(data->layer.render.addr, data->layer.tmp.addr,
	//	data->last_pixel_offset);

//data->coord.x = 10 * (); starting formula
//data->coord.y = 10 * (i * 64 - data->player.sprite.y);

	mlx_put_image_to_window(data->mlx, data->win, data->layer.tmp.img, 0, 0);
	//get_type_tile(data, &(data->map), data->coord.x, data->coord.y);
	update_x_y(data, &(data->way), &(data->coord));
	update_map_x_y(data);
	//ft_printf("%d %d\n", data->coord.x, data->coord.y);
	return (0);
}

int	close_window(t_data *data)
{
	mlx_destroy_image(data->mlx, data->layer.tmp.img);
	mlx_destroy_image(data->mlx, data->layer.render.img);
	mlx_destroy_image(data->mlx, data->layer.front.img);
	mlx_destroy_image(data->mlx, data->layer.back.img);
	mlx_destroy_image(data->mlx, data->floor.f1.img);
	mlx_destroy_image(data->mlx, data->floor.f2.img);
	mlx_destroy_image(data->mlx, data->floor.f3.img);
	mlx_destroy_image(data->mlx, data->floor.f4.img);
	mlx_destroy_image(data->mlx, data->floor.f5.img);
	mlx_destroy_image(data->mlx, data->floor.f6.img);
	mlx_destroy_image(data->mlx, data->floor.f7.img);
	mlx_destroy_image(data->mlx, data->floor.f8.img);
	mlx_destroy_image(data->mlx, data->wall.mid.img);
	mlx_destroy_image(data->mlx, data->wall.mid1.img);
	mlx_destroy_image(data->mlx, data->wall.mid2.img);
	mlx_destroy_image(data->mlx, data->wall.mid3.img);
	mlx_destroy_image(data->mlx, data->wall.mid4.img);
	mlx_destroy_image(data->mlx, data->wall.mid5.img);
	mlx_destroy_image(data->mlx, data->wall.mid51.img);
	mlx_destroy_image(data->mlx, data->wall.mid52.img);
	mlx_destroy_image(data->mlx, data->wall.mid6.img);
	mlx_destroy_image(data->mlx, data->wall.mid61.img);
	mlx_destroy_image(data->mlx, data->wall.mid7.img);
	mlx_destroy_image(data->mlx, data->wall.mid8.img);
	mlx_destroy_image(data->mlx, data->wall.side_left.img);
	mlx_destroy_image(data->mlx, data->wall.side_right.img);
	mlx_destroy_image(data->mlx, data->wall.side_down_l.img);
	mlx_destroy_image(data->mlx, data->wall.side_down_r.img);
	mlx_destroy_image(data->mlx, data->wall.side_top_r.img);
	mlx_destroy_image(data->mlx, data->wall.side_top_l.img);
	mlx_destroy_image(data->mlx, data->wall.solo_front.img);
	mlx_destroy_image(data->mlx, data->wall.solo_top.img);
	mlx_destroy_image(data->mlx, data->wall.bottom.img);
	mlx_destroy_image(data->mlx, data->wall.solo_corner.img);
	mlx_destroy_image(data->mlx, data->wall.corner_rl.img);
	mlx_destroy_image(data->mlx, data->wall.top_up.img);
	mlx_destroy_image(data->mlx, data->wall.column_base.img);
	mlx_destroy_image(data->mlx, data->wall.column_mid.img);
	mlx_destroy_image(data->mlx, data->wall.column_top.img);
	mlx_destroy_image(data->mlx, data->wall.front_l.img);
	mlx_destroy_image(data->mlx, data->wall.front_r.img);
	mlx_destroy_image(data->mlx, data->wall.top_left.img);
	mlx_destroy_image(data->mlx, data->wall.top_right.img);
	mlx_destroy_image(data->mlx, data->wall.corner_right.img);
	mlx_destroy_image(data->mlx, data->wall.corner_left.img);
	mlx_destroy_image(data->mlx, data->player.r.idle_0.img);
	mlx_destroy_image(data->mlx, data->player.r.idle_1.img);
	mlx_destroy_image(data->mlx, data->player.r.idle_2.img);
	mlx_destroy_image(data->mlx, data->player.r.idle_3.img);
	mlx_destroy_image(data->mlx, data->player.r.run_0.img);
	mlx_destroy_image(data->mlx, data->player.r.run_1.img);
	mlx_destroy_image(data->mlx, data->player.r.run_2.img);
	mlx_destroy_image(data->mlx, data->player.r.run_3.img);
	mlx_destroy_image(data->mlx, data->player.l.idle_0.img);
	mlx_destroy_image(data->mlx, data->player.l.idle_1.img);
	mlx_destroy_image(data->mlx, data->player.l.idle_2.img);
	mlx_destroy_image(data->mlx, data->player.l.idle_3.img);
	mlx_destroy_image(data->mlx, data->player.l.run_0.img);
	mlx_destroy_image(data->mlx, data->player.l.run_1.img);
	mlx_destroy_image(data->mlx, data->player.l.run_2.img);
	mlx_destroy_image(data->mlx, data->player.l.run_3.img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_map(data->map.ptr);
	exit(0);
}

int	key_press(int keycode, void *data)
{
	t_data	*d;

	d = (t_data *)data;
	if (keycode == 65307)
		close_window(data);
	if (keycode == 119 || keycode == 65362)
		d->way.up = 1;
	if (keycode == 97 || keycode == 65361)
		d->way.left = 1;
	if (keycode == 115 || keycode == 65364)
		d->way.down = 1;
	if (keycode == 100 || keycode == 65363)
		d->way.right = 1;
	return (0);
}

int	key_release(int keycode, void *data)
{
	t_data	*d;

	d = (t_data *)data;
	if (keycode == 65307)
		close_window(data);
	if (keycode == 119 || keycode == 65362)
		d->way.up = 0;
	if (keycode == 97 || keycode == 65361)
		d->way.left = 0;
	if (keycode == 115 || keycode == 65364)
		d->way.down = 0;
	if (keycode == 100 || keycode == 65363)
		d->way.right = 0;
	return (0);
}

void	setup_mlx(t_data *data)
{
	data->mlx = mlx_init();
	data->width = RES_X;//736;
	data->height = RES_Y;//480;
	data->win = mlx_new_window(data->mlx, RES_X, RES_Y, "so_long");
	import_imgs(data);
	data->last_pixel_offset = (480 * data->layer.render.line_length
			+ 736 * (data->layer.render.bits_per_pixel / 8)) - 2945;
	data->way.up = 0;
	data->way.down = 0;
	data->way.left = 0;
	data->way.right = 0;
	data->way.dir = 1;
	data->frame = 0;
	data->long_frame = 0;
	data->number_of_mouvements = 0;
	data->map.width = ft_strlen((data->map.ptr)[0]);
	data->map.height = count_number_of_lines(data->map.ptr);
	data->player.coord.x = data->width / 2 - 31;
	data->player.coord.y = data->height / 2 - 80;
	data->coord.x = 0;
	data->coord.y = 0;
	get_starting_pos(data);
	data->map.tile_coord.x = (data->coord.x / 10
			+ data->width / 2) / 64 - 1;
	data->map.tile_coord.y = (data->coord.y / 10
			+ 30 + data->height / 2) / 64 - 1;
	generate_minimap(data);
	background_put_tmp(data, 0x00232323);
}

int	game_init(t_data *data)
{
	mlx_hook(data->win, 17, 1L << 0, close_window, data);
	mlx_hook(data->win, 2, 1L << 0, key_press, data);
	mlx_hook(data->win, 3, 1L << 1, key_release, data);
	mlx_loop_hook(data->mlx, game, data);
	mlx_loop(data->mlx);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		parse_map_error(1);
	data.map.ptr = import_map(argv[1]);
	check_map(data.map.ptr);
	setup_mlx(&data);
	game_init(&data);
	return (0);
}
