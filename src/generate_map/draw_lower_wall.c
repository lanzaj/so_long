/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lower_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 01:27:37 by jlanza            #+#    #+#             */
/*   Updated: 2023/02/04 01:32:56 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_lower_wall_corner_left_continuing_down(t_data *data, int x, int y)
{
	if (is_right_corner(data, x, y))
	{
		put_img_to_front(data, &(data->wall.solo_corner),
			(x + 1) * 16, (y) * 16);
		put_img_to_back(data, &(data->wall.solo_corner),
			(x + 1) * 16, (y) * 16);
		put_img_to_back(data, &(data->wall.corner_rl),
			(x + 1) * 16, (y + 1) * 16);
	}
	else
	{
		put_img_to_front(data, &(data->wall.top_left), (x + 1) * 16, (y) * 16);
		put_img_to_back(data, &(data->wall.top_left), (x + 1) * 16, (y) * 16);
		put_img_to_back(data, &(data->wall.corner_left),
			(x + 1) * 16, (y + 1) * 16);
	}
}

void	draw_lower_wall_corner_right_continuing_down(t_data *data, int x, int y)
{
	put_img_to_front(data, &(data->wall.top_right), (x + 1) * 16, (y) * 16);
	put_img_to_back(data, &(data->wall.top_right), (x + 1) * 16, (y) * 16);
	put_img_to_back(data, &(data->wall.corner_right),
		(x + 1) * 16, (y + 1) * 16);
}

void	draw_lower_wall_right_corner(t_data *data, int x, int y)
{
	put_img_to_front(data, &(data->wall.top_right), (x + 1) * 16, (y) * 16);
	put_img_to_back(data, &(data->wall.top_right), (x + 1) * 16, (y) * 16);
	put_img_to_back(data, &(data->wall.front_r),
		(x + 1) * 16, (y + 1) * 16);
}

void	draw_lower_wall_left_corner(t_data *data, int x, int y)
{
	put_img_to_front(data, &(data->wall.top_left), (x + 1) * 16, (y) * 16);
	put_img_to_back(data, &(data->wall.top_left), (x + 1) * 16, (y) * 16);
	put_img_to_back(data, &(data->wall.front_l),
		(x + 1) * 16, (y + 1) * 16);
}

void	draw_random_lower_wall(t_data *data, int x, int y)
{
	int	random_number;

	random_number = get_random();
	put_img_to_back(data, &(data->wall.top_up), (x + 1) * 16, (y) * 16);
	put_img_to_front(data, &(data->wall.top_up), (x + 1) * 16, (y) * 16);
	if (is_tile_in_charset(data, "0", x, y + 1))
		draw_random_upper_wall(data, x, y);
	else if (random_number < 4)
		put_img_to_back(data, &(data->wall.mid7), (x + 1) * 16, (y + 1) * 16);
	else if (random_number < 8)
		put_img_to_back(data, &(data->wall.mid8), (x + 1) * 16, (y + 1) * 16);
	else
		put_img_to_back(data, &(data->wall.mid), (x + 1) * 16, (y + 1) * 16);
}
