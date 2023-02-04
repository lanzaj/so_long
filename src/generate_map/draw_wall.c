/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 01:09:42 by jlanza            #+#    #+#             */
/*   Updated: 2023/02/04 01:10:43 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	draw_upper_wall(t_data *data, int x, int y)
{
	if (is_left_corner(data, x, y))
		draw_upper_wall_corner_left_front(data, x, y);
	else if (is_right_corner(data, x, y))
		draw_upper_wall_corner_right_front(data, x, y);
	else
		draw_random_upper_wall(data, x, y);
}

static void	draw_lower_wall(t_data *data, int x, int y)
{
	if (is_column(data, x, y))
		draw_column(data, x, y);
	else if (is_left_corner(data, x, y))
	{
		if (is_wall_continuing_down(data, x, y))
			draw_lower_wall_corner_left_continuing_down(data, x, y);
		else
			draw_lower_wall_left_corner(data, x, y);
	}
	else if (is_right_corner(data, x, y))
	{
		if (is_wall_continuing_down(data, x, y))
			draw_lower_wall_corner_right_continuing_down(data, x, y);
		else
			draw_lower_wall_right_corner(data, x, y);
	}
	else
		draw_random_lower_wall(data, x, y);
}

static void	draw_side_wall(t_data *data, int x, int y)
{
	if (is_left_wall(data, x, y))
		draw_left_wall(data, x, y);
	if (is_right_wall(data, x, y))
		draw_right_wall(data, x, y);
}

void	draw_wall(t_data *data, int x, int y)
{
	if (is_lower_wall(data, x, y))
		draw_lower_wall(data, x, y);
	else if (is_upper_wall(data, x, y))
		draw_upper_wall(data, x, y);
	else if (is_side_wall(data, x, y))
		draw_side_wall(data, x, y);
}
