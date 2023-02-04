/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 22:26:54 by jlanza            #+#    #+#             */
/*   Updated: 2023/02/04 01:38:11 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_column(t_data *data, int x, int y)
{
	if (is_tile_in_charset(data, "0cPEC", x + 1, y)
		&& is_tile_in_charset(data, "0cPEC", x - 1, y)
		&& is_tile_in_charset(data, "0c", x, y + 1)
		&& is_tile_in_charset(data, "0c", x, y - 1))
	{
		draw_floor(data, x, y);
		put_img_to_back(data, &(data->floor.f1), (x + 1) * 16, (y + 2) * 16);
		data->map.ptr[y + 1][x] = 'c';
		put_img_to_back(data, &(data->wall.column_base),
			(x + 1) * 16, (y + 2) * 16);
		put_img_to_back(data, &(data->wall.column_mid),
			(x + 1) * 16, (y + 1) * 16);
		put_img_to_front(data, &(data->wall.column_top),
			(x + 1) * 16, (y) * 16);
		put_img_to_back(data, &(data->wall.column_top),
			(x + 1) * 16, (y) * 16);
	}
	else
	{
		put_img_to_front(data, &(data->wall.solo_top), (x + 1) * 16, (y) * 16);
		put_img_to_back(data, &(data->wall.solo_top), (x + 1) * 16, (y) * 16);
		put_img_to_back(data, &(data->wall.solo_front),
			(x + 1) * 16, (y + 1) * 16);
	}
}

void	draw_left_wall(t_data *data, int x, int y)
{
	put_img_to_back(data, &(data->wall.side_left), (x + 1) * 16, (y + 1) * 16);
	if (is_tile_in_charset(data, "1", x + 1, y + 1))
		put_img_to_back(data, &(data->wall.side_down_l),
			(x + 1) * 16, (y + 2) * 16);
	if (is_tile_in_charset(data, "1", x + 1, y - 1))
	{
		put_img_to_back(data, &(data->wall.side_left),
			(x + 1) * 16, (y) * 16);
		put_img_to_back(data, &(data->wall.side_top_l),
			(x + 1) * 16, (y - 1) * 16);
	}
}

void	draw_right_wall(t_data *data, int x, int y)
{
	put_img_to_back(data, &(data->wall.side_right), (x + 1) * 16, (y + 1) * 16);
	if (is_tile_in_charset(data, "1", x - 1, y + 1))
		put_img_to_back(data, &(data->wall.side_down_r),
			(x + 1) * 16, (y + 2) * 16);
	if (is_tile_in_charset(data, "1", x - 1, y - 1))
	{
		put_img_to_back(data, &(data->wall.side_right),
			(x + 1) * 16, (y) * 16);
		put_img_to_back(data, &(data->wall.side_top_r),
			(x + 1) * 16, (y - 1) * 16);
	}
}
