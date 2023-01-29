/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:05:56 by jlanza            #+#    #+#             */
/*   Updated: 2023/01/29 13:50:39 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	new_layer(t_data *data, t_img *layer)
{
	layer->width = 736;
	layer->height = 480;
	layer->img = mlx_new_image(data->mlx, layer->width, layer->height);
	layer->addr = mlx_get_data_addr(layer->img, &(layer->bits_per_pixel),
			&(layer->line_length),
			&(layer->endian));
}

void	big_new_layer(t_data *data, t_img *layer)
{
	layer->width = 3000;
	layer->height = 3000;
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
	big_new_layer(data, &(data->layer.front));
	big_new_layer(data, &(data->layer.back));
	new_layer(data, &(data->layer.tmp));
	new_layer(data, &(data->layer.render));
	import_img(data, &(data->floor.f), "./img/64_floor_1.xpm");
	import_img(data, &(data->wall.up), "./img/64_wall_up.xpm");
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
	my_mlx_background_put(data, 0x00191919);
	printf("%d\n", data->last_pixel_offset);
	data->way.up = 0;
	data->way.down = 0;
	data->way.left = 0;
	data->way.right = 0;
	data->map.width = ft_strlen((data->map.ptr)[0]);
	data->map.height = count_number_of_lines(data->map.ptr);
}

void	update_x_y(t_way *way, int *x, int *y)
{
	if (way->up && !(way->down) && (way->left || way->right))
			*y += +14;
	if (way->up && !(way->down) && !(way->left || way->right))
			*y += +20;
	if (!(way->up) && way->down && (way->left || way->right))
			*y += -14;
	if (!(way->up) && way->down && !(way->left || way->right))
			*y += -20;
	if (way->left && !(way->right) && (way->up || way ->down))
			*x += +14;
	if (way->left && !(way->right) && !(way->up || way ->down))
			*x += +20;
	if (!(way->left) && way->right && (way->up || way ->down))
			*x += -14;
	if (!(way->left) && way->right && !(way->up || way ->down))
			*x += -20;
}

void	draw_floor(t_data *data, t_coord player, t_coord tile)
{
	my_mlx_put_img_to_tmp_layer(data, &(data->floor.f),
		player.x / 10 + (tile.x * 64), player.y / 10 + (tile.y * 64));
}

void	draw_wall(t_data *data, t_coord player, t_coord tile)
{
	if (tile.y + 1 > 0 && tile.y + 1 < data->map.height
		&& data->map.ptr[tile.y + 1][tile.x] == '0')
		my_mlx_put_img_to_tmp_layer(data, &(data->wall.up),
			player.x / 10 + (tile.x * 64),
			(player.y) / 10 - 16 + (tile.y * 64));
	if (tile.y - 1 > 0 && tile.y - 1 < data->map.height
		&& data->map.ptr[tile.y - 1][tile.x] == '0')
		my_mlx_put_img_to_tmp_layer(data, &(data->wall.up),
			player.x / 10 + (tile.x * 64),
			(player.y) / 10 - 16 + (tile.y * 64));
}

void	draw_map(t_data *data, t_coord player)
{
	char	**map;
	t_coord	tile;

	map = data->map.ptr;
	tile.y = 0;
	while (tile.y < data->map.height)
	{
		tile.x = 0;
		while (tile.x < data->map.width)
		{//12 * 64 - 0 > 736
			if ((tile.x * 64) + player.x / 10 < data->width + 16
				&& (tile.y * 64) + player.y / 10 < data->height + 16
				&& tile.x * 64 + player.x / 10 > -80
				&& tile.y * 64 + player.y / 10 > -80)
			{
				if (map[tile.y][tile.x] == '0' || map[tile.y][tile.x] == 'P')
					draw_floor(data, player, tile);
				if (map[tile.y][tile.x] == '1')
					draw_wall(data, player, tile);
			}
			tile.x++;
		}
		tile.y++;
	}
}

int	game(t_data *data)
{
	static t_coord	player = {0, 0};

	pixel_put_tmp_layer(data, 735, 479, 0x00FFFFFF);
	ft_memcpy(data->layer.tmp.addr, data->layer.back.addr,
		data->last_pixel_offset);
	//my_mlx_put_img_to_tmp_layer(data, &(data->layer.back), 0, 0);
	draw_map(data, player);

	ft_memcpy(data->layer.render.addr, data->layer.tmp.addr,
		data->last_pixel_offset);
	//my_mlx_put_tmp_to_render(data);
	mlx_put_image_to_window(data->mlx, data->win, data->layer.render.img, 0, 0);
	update_x_y(&(data->way), &(player.x), &(player.y));
	return (0);
}

int	close_window(t_data *data)
{
	mlx_destroy_image(data->mlx, data->layer.front.img);
	mlx_destroy_image(data->mlx, data->layer.back.img);
	mlx_destroy_image(data->mlx, data->layer.tmp.img);
	mlx_destroy_image(data->mlx, data->layer.render.img);
	mlx_destroy_image(data->mlx, data->floor.f.img);
	mlx_destroy_image(data->mlx, data->wall.up.img);
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
	//printf("%d\n", keycode);
	if (keycode == 65307)
		close_window(data);
	if (keycode == 119)
		d->way.up = 1;
	if (keycode == 97)
		d->way.left = 1;
	if (keycode == 115)
		d->way.down = 1;
	if (keycode == 100)
		d->way.right = 1;
	return (0);
}

int	key_release(int keycode, void *data)
{
	t_data	*d;

	d = (t_data *)data;
	printf("%d\n", keycode);
	if (keycode == 65307)
		close_window(data);
	if (keycode == 119)
		d->way.up = 0;
	if (keycode == 97)
		d->way.left = 0;
	if (keycode == 115)
		d->way.down = 0;
	if (keycode == 100)
		d->way.right = 0;
	return (0);
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
