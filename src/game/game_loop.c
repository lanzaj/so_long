/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:25:21 by jlanza            #+#    #+#             */
/*   Updated: 2024/03/25 19:16:16 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

unsigned long	get_timediff_us(struct timeval t, struct timeval t0)
{
	unsigned long	ts;

	ts = (t.tv_sec - t0.tv_sec) * 1000000 + (t.tv_usec - t0.tv_usec);
	return (ts);
}

static void	update_frame(t_data *data)
{
	struct timeval	tv;
	unsigned long	time_past;
//	double			fps_wanted;
//	unsigned long	time_to_wait;

	gettimeofday(&tv, NULL);
	time_past = get_timediff_us(tv, data->last_time);
	data->speed = 130000 / time_past;

	// V = D / T
	// --> D = V / T
	// fps_wanted = (double)FPS;
	// time_to_wait = (unsigned long)(((double)1 / fps_wanted) * 1000000);
	// if (data->last_time.tv_sec)
	// {
	// 	time_past = get_timediff_us(tv, data->last_time);
	// 	if (time_past < time_to_wait)
	// 		usleep(time_to_wait - time_past);
	// }
	gettimeofday(&tv, NULL);
	data->last_time = tv;


	
	data->frame++;
	if ((data->frame) > MINI_LOOP)
		data->frame = 0;
	data->long_frame++;
	if ((data->long_frame) > LONG_LOOP)
		data->long_frame = 0;
}

int	game_loop(t_data *data)
{
	update_frame(data);
	if (!data->end.lost && !data->end.won)
	{
		banner_put_tmp(data, 0x00232323);
		draw_mini_map(data, &(data->layer.back), data->coord);
		put_coins(data, data->coord);
		put_entities(data);
		draw_mini_map_tlayer(data, &(data->layer.front), data->coord);
		put_nbr_of_mouvement(data, data->number_of_mouvements);
		mlx_put_image_to_window(data->mlx, data->win,
			data->layer.tmp.img, 0, 0);
		update_x_y(data, &(data->way), &(data->coord));
		update_map_x_y(data);
		event_player(data, data->coord.x, data->coord.y);
	}
	else
		display_endscreen(data);
	return (0);
}
