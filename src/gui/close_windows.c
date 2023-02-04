/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_windows.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:29:38 by jlanza            #+#    #+#             */
/*   Updated: 2023/02/04 00:50:56 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	close_window_part3(t_data *data)
{
	mlx_destroy_image(data->mlx, data->player.r.run_3.img);
	mlx_destroy_image(data->mlx, data->player.l.idle_0.img);
	mlx_destroy_image(data->mlx, data->player.l.idle_1.img);
	mlx_destroy_image(data->mlx, data->player.l.idle_2.img);
	mlx_destroy_image(data->mlx, data->player.l.idle_3.img);
	mlx_destroy_image(data->mlx, data->player.l.run_0.img);
	mlx_destroy_image(data->mlx, data->player.l.run_1.img);
	mlx_destroy_image(data->mlx, data->player.l.run_2.img);
	mlx_destroy_image(data->mlx, data->player.l.run_3.img);
	mlx_destroy_image(data->mlx, data->coin.c0.img);
	mlx_destroy_image(data->mlx, data->coin.c1.img);
	mlx_destroy_image(data->mlx, data->coin.c2.img);
	mlx_destroy_image(data->mlx, data->coin.c3.img);
	mlx_destroy_image(data->mlx, data->exit.exit_layer.img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_map(data->map.ptr);
	exit(0);
}

static int	close_window_part2(t_data *data)
{
	mlx_destroy_image(data->mlx, data->wall.side_top_r.img);
	mlx_destroy_image(data->mlx, data->wall.side_top_l.img);
	mlx_destroy_image(data->mlx, data->wall.solo_front.img);
	mlx_destroy_image(data->mlx, data->wall.solo_top.img);
	mlx_destroy_image(data->mlx, data->wall.bottom.img);
	mlx_destroy_image(data->mlx, data->wall.solo_corner.img);
	mlx_destroy_image(data->mlx, data->wall.corner_rl.img);
	mlx_destroy_image(data->mlx, data->wall.top_up.img);
	mlx_destroy_image(data->mlx, data->wall.column_base.img);
	mlx_destroy_image(data->mlx, data->wall.column_mid.img);
	mlx_destroy_image(data->mlx, data->wall.column_top.img);
	mlx_destroy_image(data->mlx, data->wall.front_l.img);
	mlx_destroy_image(data->mlx, data->wall.front_r.img);
	mlx_destroy_image(data->mlx, data->wall.top_left.img);
	mlx_destroy_image(data->mlx, data->wall.top_right.img);
	mlx_destroy_image(data->mlx, data->wall.corner_right.img);
	mlx_destroy_image(data->mlx, data->wall.corner_left.img);
	mlx_destroy_image(data->mlx, data->player.r.idle_0.img);
	mlx_destroy_image(data->mlx, data->player.r.idle_1.img);
	mlx_destroy_image(data->mlx, data->player.r.idle_2.img);
	mlx_destroy_image(data->mlx, data->player.r.idle_3.img);
	mlx_destroy_image(data->mlx, data->player.r.run_0.img);
	mlx_destroy_image(data->mlx, data->player.r.run_1.img);
	mlx_destroy_image(data->mlx, data->player.r.run_2.img);
	return (close_window_part3(data));
}

int	close_window(t_data *data)
{
	mlx_destroy_image(data->mlx, data->layer.tmp.img);
	mlx_destroy_image(data->mlx, data->layer.front.img);
	mlx_destroy_image(data->mlx, data->layer.back.img);
	mlx_destroy_image(data->mlx, data->floor.f1.img);
	mlx_destroy_image(data->mlx, data->floor.f2.img);
	mlx_destroy_image(data->mlx, data->floor.f3.img);
	mlx_destroy_image(data->mlx, data->floor.f4.img);
	mlx_destroy_image(data->mlx, data->floor.f5.img);
	mlx_destroy_image(data->mlx, data->floor.f6.img);
	mlx_destroy_image(data->mlx, data->floor.f7.img);
	mlx_destroy_image(data->mlx, data->floor.f8.img);
	mlx_destroy_image(data->mlx, data->floor.start.img);
	mlx_destroy_image(data->mlx, data->wall.mid.img);
	mlx_destroy_image(data->mlx, data->wall.mid1.img);
	mlx_destroy_image(data->mlx, data->wall.mid3.img);
	mlx_destroy_image(data->mlx, data->wall.mid6.img);
	mlx_destroy_image(data->mlx, data->wall.mid61.img);
	mlx_destroy_image(data->mlx, data->wall.mid7.img);
	mlx_destroy_image(data->mlx, data->wall.mid8.img);
	mlx_destroy_image(data->mlx, data->wall.side_left.img);
	mlx_destroy_image(data->mlx, data->wall.side_right.img);
	mlx_destroy_image(data->mlx, data->wall.side_down_l.img);
	mlx_destroy_image(data->mlx, data->wall.side_down_r.img);
	return (close_window_part2(data));
}
