/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_monsters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 01:32:23 by jlanza            #+#    #+#             */
/*   Updated: 2023/02/05 16:53:37 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	put_monster(t_data *data, t_monster *monster, int x, int y)
{
	t_coord	coord;

	coord.x = x;
	coord.y = y;
	if (monster->dir)
		put_player(data, coord, monster->r, data->frame);
	else
		put_player(data, coord, monster->l, data->frame);
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
