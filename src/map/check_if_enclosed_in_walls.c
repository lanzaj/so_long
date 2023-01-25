/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_enclosed_in_walls.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:54:26 by jlanza            #+#    #+#             */
/*   Updated: 2023/01/25 16:30:24 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	is_first_line_only_wall(char **map)
{
	int		i;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1')
			check_map_error(6, map);
		i++;
	}
}

static void	is_last_line_only_wall(char **map)
{
	int		i;
	int		last_line;

	last_line = count_number_of_lines(map) - 1;
	i = 0;
	while (map[last_line][i])
	{
		if (map[last_line][i] != '1')
			check_map_error(6, map);
		i++;
	}
}

static void	is_first_column_only_wall(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1')
			check_map_error(6, map);
		i++;
	}
}

static void	is_last_column_only_wall(char **map)
{
	int		i;
	size_t	last_column;

	last_column = ft_strlen(map[0]) - 1;
	i = 0;
	while (map[i])
	{
		if (map[i][last_column] != '1')
			check_map_error(6, map);
		i++;
	}
}

void	check_if_enclosed_in_walls(char **map)
{
	is_first_line_only_wall(map);
	is_last_line_only_wall(map);
	is_first_column_only_wall(map);
	is_last_column_only_wall(map);
}
