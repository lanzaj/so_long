/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:05:56 by jlanza            #+#    #+#             */
/*   Updated: 2023/01/29 00:00:01 by jlanza           ###   ########.fr       */
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
	layer->width = 800;
	layer->height = 800;
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
	import_img(data, &(data->floor.f), "./img/32_floor_1.xpm");
}

void	setup_mlx(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 736, 480, "so_long");
	import_imgs(data);
	my_mlx_background_put(data, 0x00232323);
}

int	game(t_data *data)
{
	static int	x = 0;
	static int	y = 0;

	ft_memcpy(data->layer.tmp.addr, data->layer.back.addr, 1450000);
	//my_mlx_put_img_to_tmp_layer(data, &(data->layer.back), 0, 0);
	my_mlx_put_img_to_tmp_layer(data, &(data->floor.f), x, 0);
	my_mlx_put_tmp_to_render(data);
	mlx_put_image_to_window(data->mlx, data->win, data->layer.render.img, 0, 0);
	x++;
	y++;
	return (0);
}

int	close_window(t_data *data)
{
	mlx_destroy_image(data->mlx, data->layer.front.img);
	mlx_destroy_image(data->mlx, data->layer.back.img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(data->map);
	exit(0);
}

int	key_press(int keycode, void *data)
{
	printf("%d\n", keycode);
	if (keycode == 65307)
		close_window(data);
	return (0);
}

int	game_init(t_data *data)
{
	mlx_hook(data->win, 17, 1L << 0, close_window, data);
	mlx_hook(data->win, 2, 1L << 0, key_press, data);
	mlx_loop_hook(data->mlx, game, data);
	mlx_loop(data->mlx);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		parse_map_error(1);
	data.map = import_map(argv[1]);
	check_map(data.map);
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
