/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_endscreen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:41:16 by jlanza            #+#    #+#             */
/*   Updated: 2023/02/05 19:43:58 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	display_endscreen(t_data *data)
{
	if (data->end.won)
	{
		if (data->long_frame < LONG_LOOP / 2)
			put_img_to_tmp(data, &(data->end.win), 0, 0);
		else
			put_img_to_tmp(data, &(data->end.win2), 0, 0);
	}
	else
	{
		if (data->long_frame < LONG_LOOP / 2)
			put_img_to_tmp(data, &(data->end.lose), 0, 0);
		else
			put_img_to_tmp(data, &(data->end.lose2), 0, 0);
	}
	mlx_put_image_to_window(data->mlx, data->win,
		data->layer.tmp.img, 0, 0);
}
