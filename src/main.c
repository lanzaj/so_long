/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:05:56 by jlanza            #+#    #+#             */
/*   Updated: 2023/01/28 17:55:50 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	new_layer(t_data *data, t_img *layer)
{
	data->width = 1920;
	data->heigh = 1080;
	layer->img = mlx_new_image(data->mlx, data->width, data->heigh);
	layer->addr = mlx_get_data_addr(layer->img, &(layer->bits_per_pixel),
			&(layer->line_length),
			&(layer->endian));
}

void	import_xpm(t_data *data, t_xpm *xpm, char *path)
{
	xpm->xpm = mlx_xpm_file_to_image(data->mlx,
			path, &(xpm->width), &(xpm->heigh));
	
}

void	import_imgs(t_data *data)
{
	new_layer(data, &(data->layer.front));
	new_layer(data, &(data->layer.back));
	import_xpm(data, &(data->floor.f), "./img/64_floor_1.xpm");
}

void	setup_mlx(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1920, 1080, "so_long");
	import_imgs(data);
	my_mlx_background_put(data, 0x00232323);
}

int	game(t_data *data)
{
	static int	x = 0;
	static int	y = 0;

	mlx_put_image_to_window(data->mlx, data->win, data->layer.back.img, 0, 0);
	int	i = 0;
	while (i < 5 * 64)
	{
		int	j = 0;
		while (j < 5 * 64)
		{
			mlx_put_image_to_window(data->mlx, data->win, data->floor.f.xpm, x + j, y + i);
			j += 64;
		}
		i += 64;
	}
	return (0);
}

int	close_window(t_data *data)
{
	mlx_destroy_image(data->mlx, data->layer.front.img);
	mlx_destroy_image(data->mlx, data->layer.back.img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
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
	char	**map;
	t_data	data;

	if (argc != 2)
		parse_map_error(1);
	map = import_map(argv[1]);
	check_map(map);
	setup_mlx(&data);
	free_map(map);
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
