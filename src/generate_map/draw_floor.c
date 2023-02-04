/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 01:12:45 by jlanza            #+#    #+#             */
/*   Updated: 2023/02/04 01:13:28 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_floor(t_data *data, int x, int y)
{
	int	random_number;

	random_number = get_random();
	if (random_number < 60)
		put_img_to_back(data, &(data->floor.f1), (x + 1) * 16, (y + 1) * 16);
	else if (random_number < 65)
		put_img_to_back(data, &(data->floor.f2), (x + 1) * 16, (y + 1) * 16);
	else if (random_number < 70)
		put_img_to_back(data, &(data->floor.f3), (x + 1) * 16, (y + 1) * 16);
	else if (random_number < 93)
		put_img_to_back(data, &(data->floor.f4), (x + 1) * 16, (y + 1) * 16);
	else if (random_number < 94 && is_tile_in_charset(data, "1", x - 1, y))
		put_img_to_back(data, &(data->floor.f5), (x + 1) * 16, (y + 1) * 16);
	else if (random_number < 95 && is_tile_in_charset(data, "1", x + 1, y))
		put_img_to_back(data, &(data->floor.f6), (x + 1) * 16, (y + 1) * 16);
	else if (random_number < 97 && is_tile_in_charset(data, "1", x, y - 1))
		put_img_to_back(data, &(data->floor.f7), (x + 1) * 16, (y + 1) * 16);
	else if (random_number < 98 && is_tile_in_charset(data, "1", x, y - 1))
		put_img_to_back(data, &(data->floor.f8), (x + 1) * 16, (y + 1) * 16);
	else
		put_img_to_back(data, &(data->floor.f3), (x + 1) * 16, (y + 1) * 16);
}
