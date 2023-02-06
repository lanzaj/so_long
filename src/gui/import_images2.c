/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_images2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 00:08:13 by jlanza            #+#    #+#             */
/*   Updated: 2023/02/06 13:45:18 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	import_img(t_data *data, t_img *xpm, char *path)
{
	xpm->img = mlx_xpm_file_to_image(data->mlx,
			path, &(xpm->width), &(xpm->height));
	xpm->addr = mlx_get_data_addr(xpm->img, &(xpm->bits_per_pixel),
			&(xpm->line_length), &(xpm->endian));
}

void	import_imgs_part6(t_data *data)
{
	import_img(data, &(data->undead.l.run_0), "./img/undead_run_l0.xpm");
	import_img(data, &(data->undead.l.run_1), "./img/undead_run_l1.xpm");
	import_img(data, &(data->undead.l.run_2), "./img/undead_run_l2.xpm");
	import_img(data, &(data->undead.l.run_3), "./img/undead_run_l3.xpm");
	import_img(data, &(data->end.lose), "./img/loose.xpm");
	import_img(data, &(data->end.lose2), "./img/loose2.xpm");
	import_img(data, &(data->end.win), "./img/win.xpm");
	import_img(data, &(data->end.win2), "./img/win2.xpm");
}
