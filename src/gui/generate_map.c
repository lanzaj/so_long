/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 22:26:54 by jlanza            #+#    #+#             */
/*   Updated: 2023/02/03 02:00:10 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_tile_in_charset(t_data *data, char *charset, int x, int y)
{
	if (y < 0 || y >= data->map.height || x < 0 || x >= data->map.width)
		return (ft_strchr(charset, '1') != NULL);
	return (ft_strchr(charset, data->map.ptr[y][x]) != NULL);
}

void	draw_floor(t_data *data, int x, int y)
{
	int	random_number;

	random_number = get_random();
	if (random_number < 60)
		put_img_to_back(data, &(data->floor.f1), (x + 1) * 16, (y + 1) * 16);
	else if (random_number < 65)
		put_img_to_back(data, &(data->floor.f2), (x + 1) * 16, (y + 1) * 16);
	else if (random_number < 70)
		put_img_to_back(data, &(data->floor.f3), (x + 1) * 16, (y + 1) * 16);
	else if (random_number < 93)
		put_img_to_back(data, &(data->floor.f4), (x + 1) * 16, (y + 1) * 16);
	else if (random_number < 94 && is_tile_in_charset(data, "1", x - 1, y))
		put_img_to_back(data, &(data->floor.f5), (x + 1) * 16, (y + 1) * 16);
	else if (random_number < 95 && is_tile_in_charset(data, "1", x + 1, y))
		put_img_to_back(data, &(data->floor.f6), (x + 1) * 16, (y + 1) * 16);
	else if (random_number < 97 && is_tile_in_charset(data, "1", x, y - 1))
		put_img_to_back(data, &(data->floor.f7), (x + 1) * 16, (y + 1) * 16);
	else if (random_number < 98 && is_tile_in_charset(data, "1", x, y - 1))
		put_img_to_back(data, &(data->floor.f8), (x + 1) * 16, (y + 1) * 16);
	else
		put_img_to_back(data, &(data->floor.f3), (x + 1) * 16, (y + 1) * 16);
}

int	is_column(t_data *data, int x, int y)
{
	return (is_tile_in_charset(data, "0cPEC", x + 1, y)
		&& is_tile_in_charset(data, "0cPEC", x - 1, y)
		&& is_tile_in_charset(data, "0cPEC", x, y + 1)
		&& is_tile_in_charset(data, "0cPEC", x, y - 1));
}

int	is_left_corner(t_data *data, int x, int y)
{
	return (is_tile_in_charset(data, "0cPEC", x - 1, y));
}

int	is_right_corner(t_data *data, int x, int y)
{
	return (is_tile_in_charset(data, "0cPEC", x + 1, y));
}

int	is_wall_continuing_down(t_data *data, int x, int y)
{
	return (is_tile_in_charset(data, "1", x, y + 1));
}

int	is_left_wall(t_data *data, int x, int y)
{
	return (is_tile_in_charset(data, "0cPEC", x + 1, y));
}

int	is_right_wall(t_data *data, int x, int y)
{
	return (is_tile_in_charset(data, "0cPEC", x - 1, y));
}

int	is_upper_wall(t_data *data, int x, int y)
{
	return (is_tile_in_charset(data, "0cPEC", x, y + 1));
}

int	is_lower_wall(t_data *data, int x, int y)
{
	return (is_tile_in_charset(data, "0cPEC", x, y - 1));
}

int	is_side_wall(t_data *data, int x, int y)
{
	return (is_tile_in_charset(data, "0cPEC", x + 1, y)
		|| is_tile_in_charset(data, "0cPEC", x - 1, y));
}

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

void	draw_lower_wall_corner_left_continuing_down(t_data *data, int x, int y)
{
	if (is_right_corner(data, x, y))
	{
		put_img_to_front(data, &(data->wall.solo_corner), (x + 1) * 16, (y) * 16);
		put_img_to_back(data, &(data->wall.solo_corner), (x + 1) * 16, (y) * 16);
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

void	draw_lower_wall_corner_right_continuing_down(t_data *data, int x, int y)
{
	put_img_to_front(data, &(data->wall.top_right), (x + 1) * 16, (y) * 16);
	put_img_to_back(data, &(data->wall.top_right), (x + 1) * 16, (y) * 16);
	put_img_to_back(data, &(data->wall.corner_right),
		(x + 1) * 16, (y + 1) * 16);
}

void	draw_upper_wall_corner_right_front(t_data *data, int x, int y)
{
	put_img_to_back(data, &(data->wall.top_right), (x + 1) * 16, (y) * 16);
	put_img_to_back(data, &(data->wall.front_r),
		(x + 1) * 16, (y + 1) * 16);
}

void	draw_lower_wall_right_corner(t_data *data, int x, int y)
{
	// if (!is_left_corner(data, x, y))
	// {
		put_img_to_front(data, &(data->wall.top_right), (x + 1) * 16, (y) * 16);
		put_img_to_back(data, &(data->wall.top_right), (x + 1) * 16, (y) * 16);
		put_img_to_back(data, &(data->wall.front_r),
			(x + 1) * 16, (y + 1) * 16);
	// }
}

void	draw_lower_wall_left_corner(t_data *data, int x, int y)
{
	// if (is_right_corner(data, x, y))
	// {
	// 	put_img_to_front(data, &(data->wall.solo_corner),
	// 		(x + 1) * 16, (y) * 16);
	// 	put_img_to_back(data, &(data->wall.corner_rl),
	// 		(x + 1) * 16, (y + 1) * 16);
	// }
	// else
	// {
		put_img_to_front(data, &(data->wall.top_left), (x + 1) * 16, (y) * 16);
		put_img_to_back(data, &(data->wall.top_left), (x + 1) * 16, (y) * 16);
		put_img_to_back(data, &(data->wall.front_l),
			(x + 1) * 16, (y + 1) * 16);
	// }
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

void	draw_upper_wall(t_data *data, int x, int y)
{
	if (is_left_corner(data, x, y))
		draw_upper_wall_corner_left_front(data, x, y);
	else if (is_right_corner(data, x, y))
		draw_upper_wall_corner_right_front(data, x, y);
	else
		draw_random_upper_wall(data, x, y);
}

void	draw_lower_wall(t_data *data, int x, int y)
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

void	draw_side_wall(t_data *data, int x, int y)
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
