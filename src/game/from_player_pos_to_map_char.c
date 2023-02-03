/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_player_pos_to_map_char.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:55:02 by jlanza            #+#    #+#             */
/*   Updated: 2023/02/03 22:55:34 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	from_player_x_to_map_tile_x(t_data *data, int x)
{
	return ((x / 10 + data->width / 2) / 64 - 1);
}

int	from_player_y_to_map_tile_y(t_data *data, int y)
{
	return ((y / 10 + 30 + data->height / 2) / 64 - 1);
}

char	from_player_pos_to_map_char(t_data *data, int x, int y)
{
	int	map_x;
	int	map_y;

	map_x = from_player_x_to_map_tile_x(data, x);
	map_y = from_player_y_to_map_tile_y(data, y);
	return (data->map.ptr[map_y][map_x]);
}
