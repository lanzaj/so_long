/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_coin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 00:33:02 by jlanza            #+#    #+#             */
/*   Updated: 2023/02/04 00:45:00 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	put_coin_frame(t_data *data, t_coord coord, int i, int j)
{
	if (data->frame < MINI_LOOP / 4)
		put_img_to_tmp(data, &(data->coin.c0),
			(i - coord.x) / 10, (j - coord.y) / 10);
	else if (data->frame < MINI_LOOP / 2)
		put_img_to_tmp(data, &(data->coin.c1),
			(i - coord.x) / 10, (j - coord.y) / 10);
	else if (data->frame < MINI_LOOP * 3 / 4)
		put_img_to_tmp(data, &(data->coin.c2),
			(i - coord.x) / 10, (j - coord.y) / 10);
	else
		put_img_to_tmp(data, &(data->coin.c3),
			(i - coord.x) / 10, (j - coord.y) / 10);
}

void	put_coins(t_data *data, t_coord coord)
{
	int	i;
	int	j;

	j = coord.y / 640 * 640;
	while (j < coord.y + data->height * 10)
	{
		i = coord.x / 640 * 640;
		while (i < coord.x + data->width * 10)
		{
			if (get_type_tile(&(data->map), i, j) == 'C')
			{
				put_coin_frame(data, coord, i, j);
			}
			i += 640;
		}
		j += 640;
	}
}
