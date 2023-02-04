/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 01:17:29 by jlanza            #+#    #+#             */
/*   Updated: 2023/02/04 01:17:49 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_left_wall(t_data *data, int x, int y)
{
	return (is_tile_in_charset(data, "0cPEC", x + 1, y));
}

int	is_right_wall(t_data *data, int x, int y)
{
	return (is_tile_in_charset(data, "0cPEC", x - 1, y));
}

int	is_upper_wall(t_data *data, int x, int y)
{
	return (is_tile_in_charset(data, "0cPEC", x, y + 1));
}

int	is_lower_wall(t_data *data, int x, int y)
{
	return (is_tile_in_charset(data, "0cPEC", x, y - 1));
}

int	is_side_wall(t_data *data, int x, int y)
{
	return (is_tile_in_charset(data, "0cPEC", x + 1, y)
		|| is_tile_in_charset(data, "0cPEC", x - 1, y));
}
