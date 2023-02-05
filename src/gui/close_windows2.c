/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_windows2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 00:17:29 by jlanza            #+#    #+#             */
/*   Updated: 2023/02/06 00:17:51 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_window_part6(t_data *data)
{
	mlx_destroy_image(data->mlx, data->undead.l.run_1.img);
	mlx_destroy_image(data->mlx, data->undead.l.run_2.img);
	mlx_destroy_image(data->mlx, data->undead.l.run_3.img);
	mlx_destroy_image(data->mlx, data->end.win.img);
	mlx_destroy_image(data->mlx, data->end.win2.img);
	mlx_destroy_image(data->mlx, data->end.lose.img);
	mlx_destroy_image(data->mlx, data->end.lose2.img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_map(data->map.ptr);
	exit(0);
}
