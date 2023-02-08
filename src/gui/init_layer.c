/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_layer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:20:44 by jlanza            #+#    #+#             */
/*   Updated: 2023/02/08 13:35:26 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	new_layer(t_data *data, t_img *layer)
{
	static int	i = 0;

	layer->width = data->width;
	layer->height = data->height;
	layer->img = mlx_new_image(data->mlx, layer->width, layer->height);
	if (layer->img == NULL)
		close_window_error(data);
	data->img_tab[i] = layer->img;
	i++;
	data->img_tab[i] = 0;
	layer->addr = mlx_get_data_addr(layer->img, &(layer->bits_per_pixel),
			&(layer->line_length),
			&(layer->endian));
}
