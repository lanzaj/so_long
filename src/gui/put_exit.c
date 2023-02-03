/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 00:36:01 by jlanza            #+#    #+#             */
/*   Updated: 2023/02/04 00:36:29 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	draw_exit(t_data *data, int x, int y)
{
	put_img_to_back(data, &(data->exit.exit_layer), (x + 1) * 16, (y) * 16);
}

void	put_exit_to_map(t_data *data)
{
	char	**map;
	t_coord	tile;

	map = data->map.ptr;
	tile.y = 0;
	while (tile.y < data->map.height)
	{
		tile.x = 0;
		while (tile.x < data->map.width)
		{
			if (ft_strchr("E", map[tile.y][tile.x]))
				draw_exit(data, tile.x, tile.y);
			tile.x++;
		}
		tile.y++;
	}
}
