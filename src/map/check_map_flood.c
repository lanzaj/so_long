/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_flood.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 00:11:28 by jlanza            #+#    #+#             */
/*   Updated: 2023/01/25 16:24:54 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	make_water_flow_on_tile(char **map, int i, int j)
{
	if (map[i][j] == '0' || map[i][j] == 'E' || map[i][j] == 'C')
	{
		map[i][j] = 'W';
		return (1);
	}
	return (0);
}

static char	spread_water_from_tile(char **map, int i, int j)
{
	char	b_has_spread;

	b_has_spread = 0;
	b_has_spread += make_water_flow_on_tile(map, i + 1, j);
	b_has_spread += make_water_flow_on_tile(map, i - 1, j);
	b_has_spread += make_water_flow_on_tile(map, i, j + 1);
	b_has_spread += make_water_flow_on_tile(map, i, j - 1);
	return (b_has_spread);
}

static char	flood_map(char **map)
{
	int		i;
	int		j;
	char	b_has_spread;

	b_has_spread = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P' || map[i][j] == 'W')
			{
				b_has_spread += spread_water_from_tile(map, i, j);
			}
			j++;
		}
		i++;
	}
	return (b_has_spread);
}

static int	check_flooded_map(char **map)
{
	return (count_char_in_map(map, 'C') + count_char_in_map(map, 'E'));
}

// this version of the flood check consider that you can walk on E
void	check_map_flood(char **map)
{
	char	**map_copy;
	char	bool;

	map_copy = dup_map(map);
	bool = 1;
	while (bool)
		bool = flood_map(map_copy);
	if (check_flooded_map(map_copy))
	{
		free_map(map_copy);
		check_map_error(11, map);
	}
	free_map(map_copy);
}
