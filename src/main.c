/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:05:56 by jlanza            #+#    #+#             */
/*   Updated: 2023/01/31 01:51:30 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	new_layer(t_data *data, t_img *layer)
{
	layer->width = data->width;
	layer->height = layer->width;
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
	new_layer(data, &(data->layer.front));
	new_layer(data, &(data->layer.back));
	new_layer(data, &(data->layer.tmp));
	new_layer(data, &(data->layer.render));
	import_img(data, &(data->floor.f), "./img/floor_1.xpm");
	import_img(data, &(data->wall.up), "./img/wall_mid.xpm");
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
	import_img(data, &(data->layer.test), "./img/test3.xpm");
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
				data->coord.x = 10 * (j * 64 - data->player.sprite.x) + 640;
				data->coord.y = 10 * (i * 64 - data->player.sprite.y);
				return ;
			}
			j++;
		}
		i++;
	}
}

// void	update_x_y(t_way *way, int *x, int *y)
// {
// 	if (way->up && !(way->down))
// 	{
// 		if (way->left || way->right)
// 			*y += +14;
// 		else
// 			*y += +20;
// 	}
// 	if (!(way->up) && way->down)
// 	{
// 		if (way->left || way->right)
// 			*y += -14;
// 		else
// 			*y += -20;
// 	}
// 	if (way->left && !(way->right))
// 	{
// 		if (way->up || way ->down)
// 			*x += +14;
// 		else
// 			*x += +20;
// 		way->dir = 0;
// 	}
// 	if (!(way->left) && way->right)
// 	{
// 		if (way->up || way ->down)
// 			*x += -14;
// 		else
// 			*x += -20;
// 		way->dir = 1;
// 	}
// }

// void	update_x_y(t_data *data, t_way *way, t_coord *coord)
// {
// 	if (way->up && !(way->down) && (way->left || way->right))
// 			coord->y += -14;
// 	if (way->up && !(way->down) && !(way->left || way->right))
// 			coord->y += -20;
// 	if (!(way->up) && way->down && (way->left || way->right))
// 			coord->y += +14;
// 	if (!(way->up) && way->down && !(way->left || way->right))
// 			coord->y += +20;
// 	if (way->left && !(way->right) && (way->up || way ->down))
// 			coord->x += -14;
// 	if (way->left && !(way->right) && !(way->up || way ->down))
// 			coord->x += -20;
// 	if (!(way->left) && way->right && (way->up || way ->down))
// 			coord->x += +14;
// 	if (!(way->left) && way->right && !(way->up || way ->down))
// 			coord->x += +20;
// 	if (!(way->left) && way->right)
// 		way->dir = 1;
// 	if (way->left && !(way->right))
// 		way->dir = 0;
// }

void	update_x_y(t_data *data, t_way *way, t_coord *coord)
{
	int	move;

	(void)data;
	if (way->up != way->down && way->right != way->left)
		move = 14;
	else if (way->up != way->down || way->right != way->left)
		move = 20;
	else
		move = 0;
	if (way->up && !(way->down))
			coord->y += -move;
	if (!(way->up) && way->down)
			coord->y += move;
	if (way->left && !(way->right))
	{
		coord->x += -move;
		way->dir = 0;
	}
	if (!(way->left) && way->right)
	{
		coord->x += move;
		way->dir = 1;
	}
}

void	draw_floor(t_data *data, int x, int y)
{
	put_img_to_back(data, &(data->floor.f), (x + 1) * 16, (y + 1) * 16);
}

void	draw_wall(t_data *data, int x, int y)
{
	if (y + 1 > 0 && y + 1 < data->map.height
		&& (ft_strchr("0PEC", data->map.ptr[y + 1][x])))
		put_img_to_back(data, &(data->wall.up), (x + 1) * 16, (y + 1) * 16);
	if (y - 1 > 0 && y - 1 < data->map.height
		&& (ft_strchr("0PEC", data->map.ptr[y - 1][x])))
		put_img_to_back(data, &(data->wall.up), (x + 1) * 16, (y + 1) * 16);
}

void	generate_minimap(t_data *data)
{
	char	**map;
	t_coord	tile;

	map = data->map.ptr;
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

void	put_player(t_data *d, t_coord coord, t_sprite p, int frame)
{
	if (d->way.up != d->way.down || d->way.right != d->way.left)
	{
		if (frame < LOOP_SIZE / 4)
			put_img_to_tmp(d, &(p.run_0), coord.x, coord.y);
		else if (frame < LOOP_SIZE / 2)
			put_img_to_tmp(d, &(p.run_1), coord.x, coord.y);
		else if (frame < LOOP_SIZE * 3 / 4)
			put_img_to_tmp(d, &(p.run_2), coord.x, coord.y);
		else
			put_img_to_tmp(d, &(p.run_3), coord.x, coord.y);
	}
	else
	{
		if (frame < LOOP_SIZE / 4)
			put_img_to_tmp(d, &(p.idle_0), coord.x, coord.y);
		else if (frame < LOOP_SIZE / 2)
			put_img_to_tmp(d, &(p.idle_1), coord.x, coord.y);
		else if (frame < LOOP_SIZE * 3 / 4)
			put_img_to_tmp(d, &(p.idle_2), coord.x, coord.y);
		else
			put_img_to_tmp(d, &(p.idle_3), coord.x, coord.y);
	}
}

int	game(t_data *data)
{
	data->frame++;
	if ((data->frame) > LOOP_SIZE)
		data->frame = 0;
	data->frame++;
	//ft_memcpy(data->layer.tmp.addr, data->layer.back.addr,
	//	data->last_pixel_offset);
	//draw_map(data, data->coord);
	//draw_mini_map(data, &(data->layer.test), data->coord);
	draw_mini_map(data, &(data->layer.back), data->coord);
	//draw_mini_map(data, &(data->layer.back), data->coord);
	//generate_minimap(data);
	//my_mlx_put_tmp_to_render(data);

	if (data->way.dir)
		put_player(data, data->player.sprite, data->player.r, data->frame);
	else
		put_player(data, data->player.sprite, data->player.l, data->frame);
	//ft_memcpy(data->layer.render.addr, data->layer.tmp.addr,
	//	data->last_pixel_offset);
	mlx_put_image_to_window(data->mlx, data->win, data->layer.tmp.img, 0, 0);
	update_x_y(data, &(data->way), &(data->coord));
	//ft_printf("%d %d\n", data->coord.x, data->coord.y);
	return (0);
}

int	close_window(t_data *data)
{
	mlx_destroy_image(data->mlx, data->layer.tmp.img);
	mlx_destroy_image(data->mlx, data->layer.render.img);
	mlx_destroy_image(data->mlx, data->layer.front.img);
	mlx_destroy_image(data->mlx, data->layer.back.img);
	mlx_destroy_image(data->mlx, data->layer.test.img);
	mlx_destroy_image(data->mlx, data->floor.f.img);
	mlx_destroy_image(data->mlx, data->wall.up.img);
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
	data->width = 736;
	data->height = 480;
	data->win = mlx_new_window(data->mlx, 736, 480, "so_long");
	import_imgs(data);
	data->last_pixel_offset = (480 * data->layer.render.line_length
			+ 736 * (data->layer.render.bits_per_pixel / 8)) - 2945;
	data->way.up = 0;
	data->way.down = 0;
	data->way.left = 0;
	data->way.right = 0;
	data->way.dir = 1;
	data->frame = 0;
	data->map.width = ft_strlen((data->map.ptr)[0]);
	data->map.height = count_number_of_lines(data->map.ptr);
	data->player.sprite.x = data->width / 2 - 32;
	data->player.sprite.y = data->height / 2 - 80;
	data->coord.x = 0;
	data->coord.y = 0;
	get_starting_pos(data);
	generate_minimap(data);
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

//  //////////////////////END OF CHECKING/////////////////////////////////////



// 	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length,
// 			&data.endian);

// 	////////////////////////////////////////////////////////////////

// 	int	tile_width;
// 	int	tile_height;
// void	*tile;
// tile = mlx_xpm_file_to_image(data->mlx, "./img/64_floor_1.xpm", &tile_width, &tile_height);
// mlx_put_image_to_window(data->mlx, data->mlx_win, tile, 0, 0);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 500, 0);
// 	mlx_put_image_to_window(mlx, mlx_win, tile, 500, 500);


// 	mlx_loop_hook(mlx, game, mlx_win);
// 	mlx_loop(mlx);

// 	print_map(map);
// 	free_map(map);
// 	return (0);
// }
