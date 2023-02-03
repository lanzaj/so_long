/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:13:13 by jlanza            #+#    #+#             */
/*   Updated: 2023/02/03 23:15:21 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_mini_map(t_data *data, t_img *xpm, t_coord player)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->layer.tmp.height)
	{
		x = 0;
		while (x < data->layer.tmp.width)
		{
			pixel_put_tmp_layer(data, x, y,
				get_color(xpm, (x + player.x / 10) / 4,
					(y + player.y / 10) / 4));
			x++;
		}
		y++;
	}
}

void	draw_mini_map_tlayer(t_data *data, t_img *xpm, t_coord player)
{
	int	x;
	int	y;

	y = data->layer.tmp.height / 2 + 8;
	while (y < data->layer.tmp.height / 2 + 32)
	{
		x = data->layer.tmp.width / 2 - 30;
		while (x < data->layer.tmp.width / 2 + 30)
		{
			pixel_put_tmp_layer(data, x, y,
				get_color(xpm, (x + player.x / 10) / 4,
					(y + player.y / 10) / 4));
			x++;
		}
		y++;
	}
}
