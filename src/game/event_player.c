/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 00:37:26 by jlanza            #+#    #+#             */
/*   Updated: 2024/04/23 16:36:40 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

double	dist(t_data *data, t_coord a, t_coord b)
{
	a.y = data->coord.y + (data->height / 2 - 32) * 10;
	a.x = a.x + (data->width / 2 - 32) * 10;
	return (sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)));
}

double	dist_spawn(t_coord a, t_coord b)
{
	return (sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)));
}

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
	if (dist(data, data->coord, data->orc.coord) < 500
		|| dist(data, data->coord, data->undead.coord) < 500
		|| dist(data, data->coord, data->demon.coord) < 500)
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


void	move_monster(t_data *data, t_monster *monster)
{
	int		speed = (data->speed / 4) * 3;
	t_coord	newCoord;
	newCoord.x = monster->coord.x;
	newCoord.y = monster->coord.y;
	
	if (!((abs(data->coord.x + (data->width / 2 - 32) * 10 - monster->coord.x) <= speed)
		|| (abs(data->coord.y + (data->height / 2 - 32) * 10 - monster->coord.y) <= speed)))
		speed *= SPEED_DIAGONAL;
	if (abs(data->coord.x + (data->width / 2 - 32) * 10 - monster->coord.x) > speed)
	{
		if (data->coord.x + (data->width / 2 - 32) * 10 < monster->coord.x)
			newCoord.x -= speed;
		else if ((data->coord.x + (data->width / 2 - 32) * 10 > monster->coord.x))
			newCoord.x += speed;
	}
	if (abs(data->coord.y + (data->height / 2 - 32) * 10 - monster->coord.y) > speed)
	{
		if (data->coord.y + (data->height / 2 - 32) * 10 < monster->coord.y)
			newCoord.y -= speed;
		else if (data->coord.y + (data->height / 2 - 32) * 10 > monster->coord.y)
			newCoord.y += speed;
	}
	if (dist_spawn(newCoord, monster->spawnCoord) < 800)
	{
		monster->coord.x = newCoord.x;
		monster->coord.y = newCoord.y;
		monster->moving = 1;
	}
	else
		monster->moving = 0;
}

void	event_monster(t_data *data, t_monster *monster)
{
	double distMonster = dist(data, data->coord, monster->coord);
	if (distMonster < 8000 && distMonster > 500)
	{
		move_monster(data, monster);
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
