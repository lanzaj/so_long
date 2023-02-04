/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:42:56 by jlanza            #+#    #+#             */
/*   Updated: 2023/02/04 00:50:48 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	init_data_part2(t_data *data)
{
	data->map.tile_coord.x = (data->coord.x / 10
			+ data->width / 2) / 64 - 1;
	data->map.tile_coord.y = (data->coord.y / 10
			+ 30 + data->height / 2) / 64 - 1;
	generate_minimap(data);
	background_put_tmp(data, 0x00232323);
}

void	init_data(t_data *data)
{
	data->mlx = mlx_init();
	data->width = RES_X;
	data->height = RES_Y;
	data->win = mlx_new_window(data->mlx, RES_X, RES_Y, "so_long");
	import_imgs(data);
	data->last_pixel_offset = (480 * data->layer.tmp.line_length
			+ 736 * (data->layer.tmp.bits_per_pixel / 8)) - 2945;
	data->way.up = 0;
	data->way.down = 0;
	data->way.left = 0;
	data->way.right = 0;
	data->way.dir = 1;
	data->frame = 0;
	data->long_frame = 0;
	data->number_of_mouvements = 0;
	data->map.width = ft_strlen((data->map.ptr)[0]);
	data->map.height = count_number_of_lines(data->map.ptr);
	data->player.coord.x = data->width / 2 - 31;
	data->player.coord.y = data->height / 2 - 80;
	data->coord.x = 0;
	data->coord.y = 0;
	data->nbr_of_collectible = 0;
	data->nbr_of_collectible = count_char_in_map(data->map.ptr, 'C');
	get_starting_pos(data);
	init_data_part2(data);
}
