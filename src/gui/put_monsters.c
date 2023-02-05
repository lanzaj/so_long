/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_monsters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 01:32:23 by jlanza            #+#    #+#             */
/*   Updated: 2023/02/05 20:43:25 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	put_monster_frame(t_data *d, t_coord coord, t_sprite p)
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

static void	put_monster(t_data *data, t_monster *monster, int x, int y)
{
	t_coord	coord;

	coord.x = x;
	coord.y = y;
	if (monster->dir)
		put_monster_frame(data, coord, monster->r);
	else
		put_monster_frame(data, coord, monster->l);
}

void	put_monsters(t_data *data)
{
	put_monster(data, &(data->demon),
		(data->demon.coord.x - data->coord.x) / 10 - 32,
		(data->demon.coord.y - data->coord.y) / 10 - 64);
	put_monster(data, &(data->orc),
		(data->orc.coord.x - data->coord.x) / 10 - 32,
		(data->orc.coord.y - data->coord.y) / 10 - 64);
	put_monster(data, &(data->undead),
		(data->undead.coord.x - data->coord.x) / 10 - 32,
		(data->undead.coord.y - data->coord.y) / 10 - 64);
}
