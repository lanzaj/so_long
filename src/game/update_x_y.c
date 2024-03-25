/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_x_y.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:35:56 by jlanza            #+#    #+#             */
/*   Updated: 2024/03/25 19:07:32 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	update_x_y_part2(t_data *data, t_way *way, t_coord *coord, int move)
{
	if (way->left && !(way->right) && get_type_tile_player(data,
			&(data->map), coord->x - move, coord->y) != '1'
		&& get_type_tile_player(data, &(data->map),
			coord->x - move, coord->y - 200) != '1')
	{
		coord->x += -move;
		way->dir = 0;
	}
	if (!(way->left) && way->right && get_type_tile_player(data,
			&(data->map), coord->x + move, coord->y) != '1'
		&& get_type_tile_player(data, &(data->map),
			coord->x + move, coord->y - 200) != '1')
	{
		coord->x += move;
		way->dir = 1;
	}
}

void	update_x_y(t_data *data, t_way *way, t_coord *coord)
{
	int	move;

	move = 0;
	if (way->up != way->down && way->right != way->left)
		move = data->speed * SPEED_DIAGONAL;
	else if (way->up != way->down || way->right != way->left)
		move = data->speed;
	if (way->up && !(way->down) && get_type_tile_player(data,
			&(data->map), coord->x, coord->y - move - 200) != '1')
			coord->y += -move;
	if (!(way->up) && way->down && get_type_tile_player(data,
			&(data->map), coord->x, coord->y + move + 8) != '1')
			coord->y += move;
	update_x_y_part2(data, way, coord, move);
}
