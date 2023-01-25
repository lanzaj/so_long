/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:55:57 by jlanza            #+#    #+#             */
/*   Updated: 2023/01/25 00:08:44 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	verif_if_rectangular(char **map)
{
	int		i;
	size_t	width;

	width = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != width)
			verif_map_error(5, map);
		i++;
	}
}

void	is_first_line_only_wall(char **map)
{
	int		i;

	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1')
			verif_map_error(6, map);
		i++;
	}
}

int	get_last_line_index(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i - 1);
}

void	is_last_line_only_wall(char **map)
{
	int		i;
	int		last_line;

	last_line = get_last_line_index(map);
	i = 0;
	while (map[last_line][i])
	{
		if (map[last_line][i] != '1')
			verif_map_error(6, map);
		i++;
	}
}

void	is_first_column_only_wall(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1')
			verif_map_error(6, map);
		i++;
	}
}

void	is_last_column_only_wall(char **map)
{
	int		i;
	size_t	last_column;

	last_column = ft_strlen(map[0]) - 1;
	i = 0;
	while (map[i])
	{
		if (map[i][last_column] != '1')
			verif_map_error(6, map);
		i++;
	}
}

void	verif_if_enclosed_in_walls(char **map)
{
	is_first_line_only_wall(map);
	is_last_line_only_wall(map);
	is_first_column_only_wall(map);
	is_last_column_only_wall(map);
}

int	is_not_in_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (0);
		i++;
	}
	return (1);
}

void	verif_charset(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_not_in_charset(map[i][j], "01CEP"))
				verif_map_error(10, map);
			j++;
		}
		i++;
	}
}

int	count_char_in_map(char **map, char c)
{
	int	i;
	int	j;
	int	number_of_char;

	number_of_char = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				number_of_char++;
			j++;
		}
		i++;
	}
	return (number_of_char);
}

void	verif_start_exit_and_collectible(char **map)
{
	if (count_char_in_map(map, 'P') != 1)
		verif_map_error(7, map);
	if (count_char_in_map(map, 'E') != 1)
		verif_map_error(8, map);
	if (count_char_in_map(map, 'C') == 0)
		verif_map_error(9, map);
}

void	check_map(char **map)
{
	verif_if_rectangular(map);
	verif_if_enclosed_in_walls(map);
	verif_charset(map);
	verif_start_exit_and_collectible(map);
	flood_check(map);
}
