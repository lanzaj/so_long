/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_wall2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 01:24:50 by jlanza            #+#    #+#             */
/*   Updated: 2023/02/04 01:25:04 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_column(t_data *data, int x, int y)
{
	return (is_tile_in_charset(data, "0cPEC", x + 1, y)
		&& is_tile_in_charset(data, "0cPEC", x - 1, y)
		&& is_tile_in_charset(data, "0cPEC", x, y + 1)
		&& is_tile_in_charset(data, "0cPEC", x, y - 1));
}

int	is_left_corner(t_data *data, int x, int y)
{
	return (is_tile_in_charset(data, "0cPEC", x - 1, y));
}

int	is_right_corner(t_data *data, int x, int y)
{
	return (is_tile_in_charset(data, "0cPEC", x + 1, y));
}

int	is_wall_continuing_down(t_data *data, int x, int y)
{
	return (is_tile_in_charset(data, "1", x, y + 1));
}
