/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 00:53:11 by jlanza            #+#    #+#             */
/*   Updated: 2023/02/04 00:57:00 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// void	pixel_put_front_layert(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	if (!(x < 0 || x >= (*data).layer.front.width || y < 0
// 			|| y >= (*data).layer.front.height
// 			|| color == -1 || get_t(color) == 255))
// 	{
// 		dst = (*data).layer.front.addr + (y * (*data).layer.front.line_length
// 				+ x * ((*data).layer.front.bits_per_pixel / 8));
// 		*(unsigned int *)dst = color;
// 	}
// }

void	pixel_put_front_layer(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (!(x < 0 || x >= (*data).layer.front.width || y < 0
			|| y >= (*data).layer.front.height
			|| color == -1 || get_t(color) == 255))
	{
		dst = (*data).layer.front.addr + (y * (*data).layer.front.line_length
				+ x * ((*data).layer.front.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	pixel_put_back_layer(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (!(x < 0 || x >= (*data).layer.back.width || y < 0
			|| y >= (*data).layer.back.height
			|| color == -1 || get_t(color) == 255))
	{
		dst = (*data).layer.back.addr + (y * (*data).layer.back.line_length
				+ x * ((*data).layer.back.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	pixel_put_tmp_layer(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (!(x < 0 || x >= (*data).layer.tmp.width || y < 0
			|| y >= (*data).layer.tmp.height
			|| color == -1 || get_t(color) == 255))
	{
		dst = (*data).layer.tmp.addr + (y * (*data).layer.tmp.line_length
				+ x * ((*data).layer.tmp.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}
