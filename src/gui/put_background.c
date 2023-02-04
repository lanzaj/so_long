/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_background.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 01:03:39 by jlanza            #+#    #+#             */
/*   Updated: 2023/02/04 01:04:09 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	background_put_tmp(t_data *data, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->layer.tmp.height)
	{
		x = 0;
		while (x < data->layer.tmp.width)
		{
			pixel_put_tmp_layer(data, x, y, color);
			x++;
		}
		y++;
	}
}

void	background_put_back(t_data *data, int color)
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
