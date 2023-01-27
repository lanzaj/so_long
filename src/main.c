/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:05:56 by jlanza            #+#    #+#             */
/*   Updated: 2023/01/27 13:45:23 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	setup_mlx(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, 1920, 1080, "so_long");
	data->width = 1920;
	data->heigh = 1080;
	data->img = mlx_new_image(data->mlx, data->width, data->heigh);
	data->addr = mlx_get_data_addr(data->img, &(data->bits_per_pixel),
			&(data->line_length),
			&(data->endian));
	my_mlx_background_put(data, 0x00FF0000);

	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

int	game(void)
{
	//write(1, "here\n", 5);
	return (0);
}

int	close_window(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
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
	mlx_hook(data->mlx_win, 17, 1L << 0, close_window, data);
	mlx_hook(data->mlx_win, 2, 1L << 0, key_press, data);
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
	game_init(&data);
/* 1: Create every hook
	2: Launch loop */
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
