/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type_tile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:57:52 by jlanza            #+#    #+#             */
/*   Updated: 2023/02/03 22:58:39 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	get_type_tile_player(t_data *data, t_map *map, int x, int y)
{
	int	map_x;
	int	map_xr;
	int	map_xl;
	int	map_y;

	map_x = (x / 10 + data->width / 2) / 64 - 1;
	map_xr = (x / 10 + 20 + data->width / 2) / 64 - 1;
	map_xl = (x / 10 - 20 + data->width / 2) / 64 - 1;
	map_y = (y / 10 + 30 + data->height / 2) / 64 - 1;
	if (map_x < 0 || map_x >= map->width)
		return ('1');
	if (map_y < 0 || map_y >= map->height)
		return ('1');
	if (map->ptr[map_y][map_xr] == '1' || '1' == map->ptr[map_y][map_xl])
		return ('1');
	return (map->ptr[map_y][map_x]);
}

char	get_type_tile_under_player(t_data *data, t_map *map, int x, int y)
{
	int	map_x;
	int	map_y;

	map_x = (x / 10 + data->width / 2) / 64 - 1;
	map_y = (y / 10 + 30 + data->height / 2) / 64 - 1;
	if (map_x < 0 || map_x >= map->width)
		return ('1');
	if (map_y < 0 || map_y >= map->height)
		return ('1');
	return (map->ptr[map_y][map_x]);
}

char	get_type_tile(t_map *map, int x, int y)
{
	int	map_x;
	int	map_y;

	map_x = (x / 10) / 64 - 1;
	map_y = (y / 10) / 64 - 1;
	if (map_x < 0 || map_x >= map->width)
		return ('1');
	if (map_y < 0 || map_y >= map->height)
		return ('1');
	return (map->ptr[map_y][map_x]);
}
