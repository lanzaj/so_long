/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:25:21 by jlanza            #+#    #+#             */
/*   Updated: 2023/02/03 22:25:39 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	game_loop(t_data *data)
{
	data->frame++;
	if ((data->frame) > MINI_LOOP)
		data->frame = 0;
	data->long_frame++;
	if ((data->long_frame) > LONG_LOOP)
		data->long_frame = 0;
	draw_mini_map(data, &(data->layer.back), data->coord);
	put_coins(data, data->coord);
	if (data->way.dir)
		put_player(data, data->player.coord, data->player.r, data->frame);
	else
		put_player(data, data->player.coord, data->player.l, data->frame);
	draw_mini_map_tlayer(data, &(data->layer.front), data->coord);
	mlx_put_image_to_window(data->mlx, data->win, data->layer.tmp.img, 0, 0);
	update_x_y(data, &(data->way), &(data->coord));
	update_map_x_y(data);
	event_player(data, data->coord.x, data->coord.y);
	return (0);
}
