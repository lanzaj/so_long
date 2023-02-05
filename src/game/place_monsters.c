/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_monsters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 21:55:00 by jlanza            #+#    #+#             */
/*   Updated: 2023/02/05 19:56:12 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	update_map_monster(char **map, t_coord tile)
{
	map[tile.y + 2][tile.x + 2] = 'M';
}

void	spawn_monster(t_data *data, char **map, t_coord tile, int n_monster)
{
	t_monster	*monster;

	if (n_monster == 0)
		monster = &(data->demon);
	else if (n_monster == 1)
		monster = &(data->orc);
	else if (n_monster == 2)
		monster = &(data->undead);
	else
		return ;
	update_map_monster(map, tile);
	monster->coord.x = (tile.x + 3) * 640;
	monster->coord.y = (tile.y + 3) * 640;
}

int	is_monster_spawnable(t_data *data, t_coord tile)
{
	int	i;
	int	j;

	j = 0;
	while (j < 5)
	{
		i = 0;
		while (i < 5)
		{
			if (!is_tile_in_charset(data, "0c", i + tile.x, j + tile.y))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

void	place_monsters(t_data *data)
{
	char	**map;
	t_coord	tile;
	int		n_monster;

	map = data->map.ptr;
	n_monster = 0;
	tile.y = 0;
	while (tile.y < data->map.height)
	{
		tile.x = 0;
		while (tile.x < data->map.width)
		{
			if (is_monster_spawnable(data, tile))
			{
				spawn_monster(data, map, tile, n_monster);
				n_monster++;
			}
			tile.x++;
		}
		tile.y++;
	}
}
