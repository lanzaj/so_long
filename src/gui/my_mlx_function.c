/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:47:16 by jlanza            #+#    #+#             */
/*   Updated: 2023/01/28 17:54:23 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	pixel_put_front_layer(t_data *data, int x, int y, int color)
{
	char	*dst;
	t_img	*front;

	front = &(data->layer.front);
	dst = front->addr + (y * front->line_length + x * (front->bits_per_pixel / 8));
	if (!(x < 0 || x >= data->width || y < 0 || y >= data->heigh))
		*(unsigned int*)dst = color;
}

void	pixel_put_back_layer(t_data *data, int x, int y, int color)
{
	char	*dst;
	t_img	*back;

	back = &(data->layer.back);
	dst = back->addr + (y * back->line_length + x * (back->bits_per_pixel / 8));
	if (!(x < 0 || x >= data->width || y < 0 || y >= data->heigh))
		*(unsigned int*)dst = color;
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
			pixel_put_back_layer(data, i, j, color);
			j++;
		}
		i++;
	}
}

void	my_mlx_put_xpm_to_layer(t_data *data, t_xpm *xpm, int x, int y)
{
	int	i;
	int	j;

	i = x;
	while (i < xpm->heigh + y)
	{
		j = y;
		while (j < xpm->width + x)
		{
			pixel_put_back_layer(data, i, j, xpm[i][j])
			j++;
		}
		i++;
	}
}
