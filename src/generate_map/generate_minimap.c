/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_minimap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:10:30 by jlanza            #+#    #+#             */
/*   Updated: 2023/02/04 00:48:19 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	generate_minimap(t_data *data)
{
	char	**map;
	t_coord	tile;

	map = data->map.ptr;
	background_put_back(data, 0x00232323);
	tile.y = 0;
	while (tile.y < data->map.height)
	{
		tile.x = 0;
		while (tile.x < data->map.width)
		{
			if (ft_strchr("0EC", map[tile.y][tile.x]))
				draw_floor(data, tile.x, tile.y);
			if (map[tile.y][tile.x] == '1')
				draw_wall(data, tile.x, tile.y);
			if (ft_strchr("P", map[tile.y][tile.x]))
				put_img_to_back(data, &(data->floor.start),
					(tile.x + 1) * 16, (tile.y + 1) * 16);
			tile.x++;
		}
		tile.y++;
	}
}
