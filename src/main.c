/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:05:56 by jlanza            #+#    #+#             */
/*   Updated: 2023/01/26 18:55:14 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	if (!(x < 0 || x >= data->width || y < 0 || y >= data->heigh))
		*(unsigned int*)dst = color;
}

void	my_mlx_square_put(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 100)
	{
		j = 0;
		while (j < 100)
		{
			my_mlx_pixel_put(data, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	my_mlx_circle_put(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 100)
	{
		j = 0;
		while (j < 100)
		{
			if (sqrt(pow((x + i) - (50 + x), 2) + pow((y + j) - (50 + y), 2)) < 50)
				my_mlx_pixel_put(data, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	my_mlx_triange_put(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 100)
	{
		j = 0;
		while (j < i / 2)
		{
			my_mlx_pixel_put(data, 50 - j + x, y + i, color);
			my_mlx_pixel_put(data, 50 + j + x, y + i, color);
			j++;
		}
		i++;
	}
}

void	my_mlx_background_put(t_data *data, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->width)
	{
		j = 0;
		while (j < data->heigh)
		{
			my_mlx_pixel_put(data, i, j, color);
			j++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	char	**map;
	void	*mlx;
	void	*mlx_win;
	t_data	img;


	if (argc != 2)
		parse_map_error(1);
	map = import_map(argv[1]);
	check_map(map);
 //////////////////////END OF CHECKING/////////////////////////////////////
	mlx = mlx_init();
	img.width = 1920;
	img.heigh = 1080;
	mlx_win = mlx_new_window(mlx, 1920, 1080, "so_long");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);

	my_mlx_background_put(&img, 0x00FFFFFF);
	my_mlx_circle_put(&img, 1000, 500, 0x00FF0000);
	my_mlx_square_put(&img, 5, 5, 0x0000FF00);
	my_mlx_triange_put(&img, 5, 5, 0x000000FF);
	my_mlx_pixel_put(&img, 1919, 1079, 0x00FF0000);
	my_mlx_pixel_put(&img, 0, 0, 0x00FF0000);

	int	tile_width;
	int	tile_height;
	void	*tile;
	tile = mlx_xpm_file_to_image(mlx, "./img/64_floor_1.xpm", &tile_width, &tile_height);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 500, 0);
	mlx_put_image_to_window(mlx, mlx_win, tile, 500, 500);
	int	t;
	t = 0;
	while (t <= 1000)
	{
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0 + t, 0);
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0 + t, 0);
		t = t + 12;
	}
	mlx_loop(mlx);

	print_map(map);
	free_map(map);
	return (0);
}
