/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_starting_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:01:42 by jlanza            #+#    #+#             */
/*   Updated: 2023/02/03 23:02:14 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_starting_pos(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.height)
	{
		j = 0;
		while (j < data->map.width)
		{
			if (data->map.ptr[i][j] == 'P')
			{
				data->coord.x = 10 * (j * 64 - data->player.coord.x + 64);
				data->coord.y = 10 * (i * 64 - data->player.coord.y);
				return ;
			}
			j++;
		}
		i++;
	}
}
