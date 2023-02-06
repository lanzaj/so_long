/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:28:22 by jlanza            #+#    #+#             */
/*   Updated: 2023/02/06 12:32:20 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**dup_map(char **map)
{
	char	**map_copy;
	int		i;

	map_copy = ft_calloc(count_number_of_lines(map) + 1, sizeof(*map));
	if (map_copy == NULL)
	{
		free_map(map);
		exit(1);
	}
	i = 0;
	while (map[i])
	{
		map_copy[i] = ft_strdup(map[i]);
		if (map_copy[i] == NULL)
		{
			free_map(map);
			free_map(map_copy);
			exit(1);
		}
		i++;
	}
	return (map_copy);
}
