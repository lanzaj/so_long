/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map_x_y.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 00:27:01 by jlanza            #+#    #+#             */
/*   Updated: 2023/02/04 19:29:01 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	update_map_x_y(t_data *data)
{
	if (data->map.tile_coord.x != (data->coord.x / 10
			+ data->width / 2) / 64 - 1)
	{
		data->map.tile_coord.x = (data->coord.x / 10
				+ data->width / 2) / 64 - 1;
		data->number_of_mouvements++;
		ft_printf("number of mouvements: %d\n", data->number_of_mouvements);
	}
	if (data->map.tile_coord.y != (data->coord.y / 10
			+ 30 + data->height / 2) / 64 - 1)
	{
		data->map.tile_coord.y = (data->coord.y / 10
				+ 30 + data->height / 2) / 64 - 1;
		data->number_of_mouvements++;
		ft_printf("number of mouvements: %d\n", data->number_of_mouvements);
	}
	put_nbr_of_mouvement(data, data->number_of_mouvements);
}
