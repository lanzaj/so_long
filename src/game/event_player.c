/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 00:37:26 by jlanza            #+#    #+#             */
/*   Updated: 2023/02/05 20:21:36 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	event_player(t_data *data, int x, int y)
{
	if ('C' == get_type_tile_under_player(data, &(data->map), x, y))
	{
		data->nbr_of_collectible--;
		data->map.ptr[from_player_y_to_map_tile_y(data, y)]
		[from_player_x_to_map_tile_x(data, x)] = '0';
		if (data->nbr_of_collectible == 0)
			put_exit_to_map(data);
	}
	if ('E' == get_type_tile_under_player(data, &(data->map), x, y)
		&& !data->nbr_of_collectible)
		data->end.won = 1;
	if ('M' == get_type_tile_under_player(data, &(data->map), x, y))
		data->end.lost = 1;
	if (data->coord.x + (data->width / 2 - 32) * 10 > data->demon.coord.x)
		data->demon.dir = 1;
	else
		data->demon.dir = 0;
	if (data->coord.x + (data->width / 2 - 32) * 10 > data->undead.coord.x)
		data->undead.dir = 1;
	else
		data->undead.dir = 0;
	if (data->coord.x + (data->width / 2 - 32) * 10 > data->orc.coord.x)
		data->orc.dir = 1;
	else
		data->orc.dir = 0;
}
