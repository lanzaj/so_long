/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_funtion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:47:16 by jlanza            #+#    #+#             */
/*   Updated: 2023/01/27 11:48:16 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
			if (sqrt(pow((x + i) - (50 + x), 2)
					+ pow((y + j) - (50 + y), 2)) < 50)
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
