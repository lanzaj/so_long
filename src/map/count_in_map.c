/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_in_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:30:31 by jlanza            #+#    #+#             */
/*   Updated: 2023/01/25 16:32:38 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_number_of_lines(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
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
