/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_to_layer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 01:05:28 by jlanza            #+#    #+#             */
/*   Updated: 2023/02/04 01:06:01 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_img_to_back(t_data *data, t_img *xpm, int x, int y)
{
	int	i;
	int	j;

	i = y;
	while (i < xpm->height + y)
	{
		j = x;
		while (j < xpm->width + x)
		{
			pixel_put_back_layer(data, j, i, get_color(xpm, j - x, i - y));
			j++;
		}
		i++;
	}
}

void	put_img_to_front(t_data *data, t_img *xpm, int x, int y)
{
	int	i;
	int	j;

	i = y;
	while (i < xpm->height + y)
	{
		j = x;
		while (j < xpm->width + x)
		{
			pixel_put_front_layer(data, j, i, get_color(xpm, j - x, i - y));
			j++;
		}
		i++;
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

void	put_img_to_fullscreen_tmp(t_data *data, t_img *xpm)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			pixel_put_tmp_layer(data, j, i, get_color(xpm, j * xpm->width / data->width,
														i * xpm->height / data->height));
			j++;
		}
		i++;
	}
}