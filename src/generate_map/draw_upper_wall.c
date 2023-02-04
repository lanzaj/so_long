/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_upper_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 01:28:08 by jlanza            #+#    #+#             */
/*   Updated: 2023/02/04 01:31:13 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_upper_wall_corner_left_front(t_data *data, int x, int y)
{
	if (is_right_corner(data, x, y))
	{
		put_img_to_back(data, &(data->wall.bottom), (x + 1) * 16, (y) * 16);
		put_img_to_back(data, &(data->wall.solo_front),
			(x + 1) * 16, (y + 1) * 16);
	}
	else
	{
		put_img_to_back(data, &(data->wall.top_left), (x + 1) * 16, (y) * 16);
		put_img_to_back(data, &(data->wall.front_l),
			(x + 1) * 16, (y + 1) * 16);
	}
}

void	draw_upper_wall_corner_right_front(t_data *data, int x, int y)
{
	put_img_to_back(data, &(data->wall.top_right), (x + 1) * 16, (y) * 16);
	put_img_to_back(data, &(data->wall.front_r),
		(x + 1) * 16, (y + 1) * 16);
}

void	draw_random_upper_wall(t_data *data, int x, int y)
{
	int	random_number;

	put_img_to_back(data, &(data->wall.top_up), (x + 1) * 16, (y) * 16);
	random_number = get_random();
	if (random_number < 5)
		put_img_to_back(data, &(data->wall.mid1), (x + 1) * 16, (y + 1) * 16);
	else if (random_number < 10)
		put_img_to_back(data, &(data->wall.mid3), (x + 1) * 16, (y + 1) * 16);
	else if (random_number < 15 && is_tile_in_charset(data, "0", x, y + 1))
	{
		put_img_to_back(data, &(data->wall.mid6), (x + 1) * 16, (y + 1) * 16);
		put_img_to_back(data, &(data->wall.mid61), (x + 1) * 16, (y + 2) * 16);
		data->map.ptr[y + 1][x] = 'c';
	}
	else
		put_img_to_back(data, &(data->wall.mid), (x + 1) * 16, (y + 1) * 16);
}
