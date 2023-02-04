/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_tile_in_charset.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 01:14:40 by jlanza            #+#    #+#             */
/*   Updated: 2023/02/04 01:14:55 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_tile_in_charset(t_data *data, char *charset, int x, int y)
{
	if (y < 0 || y >= data->map.height || x < 0 || x >= data->map.width)
		return (ft_strchr(charset, '1') != NULL);
	return (ft_strchr(charset, data->map.ptr[y][x]) != NULL);
}
