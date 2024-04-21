/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_entities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 01:32:23 by jlanza            #+#    #+#             */
/*   Updated: 2024/04/21 18:19:15 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	put_monster_frame(t_data *d, t_coord coord, t_sprite p, int moving)
{
	if (moving)
	{
		if (d->frame < MINI_LOOP / 4)
			put_img_to_tmp(d, &(p.run_0), coord.x, coord.y);
		else if (d->frame < MINI_LOOP / 2)
			put_img_to_tmp(d, &(p.run_1), coord.x, coord.y);
		else if (d->frame < MINI_LOOP * 3 / 4)
			put_img_to_tmp(d, &(p.run_2), coord.x, coord.y);
		else
			put_img_to_tmp(d, &(p.run_3), coord.x, coord.y);
	}
	else
	{
		if (d->long_frame < LONG_LOOP / 4)
			put_img_to_tmp(d, &(p.idle_0), coord.x, coord.y);
		else if (d->long_frame < LONG_LOOP / 2)
			put_img_to_tmp(d, &(p.idle_1), coord.x, coord.y);
		else if (d->long_frame < LONG_LOOP * 3 / 4)
			put_img_to_tmp(d, &(p.idle_2), coord.x, coord.y);
		else
			put_img_to_tmp(d, &(p.idle_3), coord.x, coord.y);
	}
}

static void	put_monster(t_data *data, t_monster *monster, int x, int y)
{
	t_coord	coord;

	coord.x = x;
	coord.y = y;
	if (monster->dir)
		put_monster_frame(data, coord, monster->r, monster->moving);
	else
		put_monster_frame(data, coord, monster->l, monster->moving);
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void	put_entities(t_data *data)
{
	int	y_player = data->player.coord.y ;
	int y_demon = (data->demon.coord.y - data->coord.y) / 10 - 32;
	int	y_undead = (data->undead.coord.y - data->coord.y) / 10 - 32;
	int y_orc = (data->orc.coord.y - data->coord.y) / 10 - 32;
	int	coords_Y[4];
	coords_Y[0] = y_player;
	coords_Y[1] = y_demon;
	coords_Y[2] = y_undead;
	coords_Y[3] = y_orc;

	qsort(coords_Y, 4, sizeof(int), compare);
	for (int i = 0; i <= 4; ++i)
	{
		//if (i > 0 && coords_Y[i] == coords_Y[i - 1])
		//	break;
		if (coords_Y[i] == y_player)
			put_player(data);
		if (coords_Y[i] == y_demon)
			put_monster(data, &(data->demon),
				(data->demon.coord.x - data->coord.x) / 10 - 32,
				(data->demon.coord.y - data->coord.y) / 10 - 64);
		if (coords_Y[i] == y_orc)
			put_monster(data, &(data->orc),
				(data->orc.coord.x - data->coord.x) / 10 - 32,
				(data->orc.coord.y - data->coord.y) / 10 - 64);
		if (coords_Y[i] == y_undead)
			put_monster(data, &(data->undead),
				(data->undead.coord.x - data->coord.x) / 10 - 32,
				(data->undead.coord.y - data->coord.y) / 10 - 64);
	}
}
