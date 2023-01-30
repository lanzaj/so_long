/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:47:16 by jlanza            #+#    #+#             */
/*   Updated: 2023/01/30 20:20:59 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

unsigned char	get_t(int trgb)
{
	return (((unsigned char *)&trgb)[3]);
}

int	get_color(t_img *xpm, int x, int y)
{
	if (x < 0 || x >= xpm->width || y < 0 || y >= xpm->height)
		return (-1);
	return (*(int *)(xpm->addr + (x * (xpm->bits_per_pixel / 8)
			+ y * xpm->line_length)));
}

void	pixel_put_front_layer(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (!(x < 0 || x >= (*data).layer.front.width || y < 0
			|| y >= (*data).layer.front.height
			|| color == -1 || get_t(color) == 255))
	{
		dst = (*data).layer.front.addr + (y * (*data).layer.front.line_length
				+ x * ((*data).layer.front.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	pixel_put_tmp_layer(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (!(x < 0 || x >= (*data).layer.tmp.width || y < 0
			|| y >= (*data).layer.tmp.height
			|| color == -1 || get_t(color) == 255))
	{
		dst = (*data).layer.tmp.addr + (y * (*data).layer.tmp.line_length
				+ x * ((*data).layer.tmp.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	pixel_put_back_layer(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (!(x < 0 || x >= (*data).layer.back.width || y < 0
			|| y >= (*data).layer.back.height
			|| color == -1 || get_t(color) == 255))
	{
		dst = (*data).layer.back.addr + (y * (*data).layer.back.line_length
				+ x * ((*data).layer.back.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	pixel_put_render_layer(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (!(x < 0 || x >= (*data).layer.render.width || y < 0
			|| y >= (*data).layer.render.height
			|| color == -1 || get_t(color) == 255))
	{
		dst = (*data).layer.render.addr + (y * (*data).layer.render.line_length
				+ x * ((*data).layer.render.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	my_mlx_background_put(t_data *data, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->layer.back.height)
	{
		x = 0;
		while (x < data->layer.back.width)
		{
			pixel_put_back_layer(data, x, y, color);
			x++;
		}
		y++;
	}
}



void	put_img_to_tmp(t_data *data, t_img *xpm, int x, int y)
{
	int	i;
	int	j;

	i = y;
	while (i < xpm->height + y)
	{
		j = x;
		while (j < xpm->width + x)
		{
			pixel_put_tmp_layer(data, j, i, get_color(xpm, j - x, i - y));
			j++;
		}
		i++;
	}
}

void	put_16x16img_to_64x64tmp(t_data *data, t_img *xpm, int x, int y)
{
	int	i;
	int	j;

	i = y;
	while (i < xpm->height + y)
	{
		j = x;
		while (j < xpm->width + x)
		{
			pixel_put_tmp_layer(data, j, i, get_color(xpm, (j - x) / 4, (i - y)/4));
			j++;
		}
		i++;
	}
}

void	my_mlx_put_tmp_to_render(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->layer.tmp.height)
	{
		j = 0;
		while (j < data->layer.tmp.width)
		{
			pixel_put_render_layer(data, j, i,
				get_color(&(data->layer.tmp), j, i));
			j++;
		}
		i++;
	}
}
