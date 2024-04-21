/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 00:37:26 by jlanza            #+#    #+#             */
/*   Updated: 2024/04/21 18:16:22 by jlanza           ###   ########.fr       */
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

double	dist(t_data *data, t_coord a, t_coord b)
{
	a.y = data->coord.y + (data->height / 2 - 32) * 10;
	a.x = a.x + (data->width / 2 - 32) * 10;
	return (sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)));
}

void	move_monster(t_data *data, t_monster *monster)
{
	int speed = 40;
	if ((abs(data->coord.x + (data->width / 2 - 32) * 10 - monster->coord.x) <= speed)
		|| (abs(data->coord.y + (data->height / 2 - 32) * 10 - monster->coord.y) <= speed))
		speed *= SPEED_CARDINAL;
	if (abs(data->coord.x + (data->width / 2 - 32) * 10 - monster->coord.x) > speed)
	{
		if (data->coord.x + (data->width / 2 - 32) * 10 < monster->coord.x)
			monster->coord.x -= speed;
		else
			monster->coord.x += speed;
	}
	if (abs(data->coord.y + (data->height / 2 - 32) * 10 - monster->coord.y) > speed)
	{
		if (data->coord.y + (data->height / 2 - 32) * 10 < monster->coord.y)
			monster->coord.y -= speed;
		else
			monster->coord.y += speed;
	}
}

void	event_monster(t_data *data, t_monster *monster)
{
	double distMonster = dist(data, data->coord, monster->coord);
	if (distMonster < 4000 && distMonster > 500)
	{
		move_monster(data, monster);
		monster->moving = 1;
	}
	else
		monster->moving = 0;
}

void	event_monsters(t_data *data)
{
	event_monster(data, &(data->orc));
	event_monster(data, &(data->demon));
	event_monster(data, &(data->undead));
}
