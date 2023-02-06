/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:55:57 by jlanza            #+#    #+#             */
/*   Updated: 2023/02/06 00:45:46 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	check_if_rectangular(char **map)
{
	int		i;
	size_t	width;

	width = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != width)
			check_map_error(5, map);
		i++;
	}
}

static void	check_charset(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_strchr("01CEP", map[i][j]))
				check_map_error(10, map);
			j++;
		}
		i++;
	}
}

static void	check_start_exit_and_collectible(char **map)
{
	if (count_char_in_map(map, 'P') != 1)
		check_map_error(7, map);
	if (count_char_in_map(map, 'E') != 1)
		check_map_error(8, map);
	if (count_char_in_map(map, 'C') == 0)
		check_map_error(9, map);
}

static void	check_size(char **map)
{
	if ((count_number_of_lines(map) > 43) || (ft_strlen(map[0]) > 80))
		check_map_error(12, map);
}

void	check_map(char **map)
{
	check_if_rectangular(map);
	check_size(map);
	check_if_enclosed_in_walls(map);
	check_charset(map);
	check_start_exit_and_collectible(map);
	check_map_flood(map);
}
