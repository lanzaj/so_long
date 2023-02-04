/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:26:40 by jlanza            #+#    #+#             */
/*   Updated: 2023/02/04 00:51:04 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	import_img(t_data *data, t_img *xpm, char *path)
{
	xpm->img = mlx_xpm_file_to_image(data->mlx,
			path, &(xpm->width), &(xpm->height));
	xpm->addr = mlx_get_data_addr(xpm->img, &(xpm->bits_per_pixel),
			&(xpm->line_length), &(xpm->endian));
}

static void	import_imgs_part3(t_data *data)
{
	import_img(data, &(data->player.r.run_3), "./img/64_knight_run_r3.xpm");
	import_img(data, &(data->player.l.idle_0), "./img/64_knight_idle_l0.xpm");
	import_img(data, &(data->player.l.idle_1), "./img/64_knight_idle_l1.xpm");
	import_img(data, &(data->player.l.idle_2), "./img/64_knight_idle_l2.xpm");
	import_img(data, &(data->player.l.idle_3), "./img/64_knight_idle_l3.xpm");
	import_img(data, &(data->player.l.run_0), "./img/64_knight_run_l0.xpm");
	import_img(data, &(data->player.l.run_1), "./img/64_knight_run_l1.xpm");
	import_img(data, &(data->player.l.run_2), "./img/64_knight_run_l2.xpm");
	import_img(data, &(data->player.l.run_3), "./img/64_knight_run_l3.xpm");
	import_img(data, &(data->coin.c0), "./img/coin_f0.xpm");
	import_img(data, &(data->coin.c1), "./img/coin_f1.xpm");
	import_img(data, &(data->coin.c2), "./img/coin_f2.xpm");
	import_img(data, &(data->coin.c3), "./img/coin_f3.xpm");
	import_img(data, &(data->exit.exit_layer), "./img/exit_ladder.xpm");
}

static void	import_imgs_part2(t_data *data)
{
	import_img(data, &(data->wall.side_top_l), "./img/wall_side_top_l.xpm");
	import_img(data, &(data->wall.side_top_r), "./img/wall_side_top_r.xpm");
	import_img(data, &(data->wall.corner_rl), "./img/wall_corner_r_l.xpm");
	import_img(data, &(data->wall.solo_front), "./img/wall_solo_front.xpm");
	import_img(data, &(data->wall.solo_top), "./img/wall_top_solo.xpm");
	import_img(data, &(data->wall.bottom), "./img/wall_top_solo_bottom.xpm");
	import_img(data, &(data->wall.solo_corner), "./img/solo_corner.xpm");
	import_img(data, &(data->wall.top_up), "./img/wall_top_mid.xpm");
	import_img(data, &(data->wall.column_top), "./img/column_top.xpm");
	import_img(data, &(data->wall.column_mid), "./img/column_mid.xpm");
	import_img(data, &(data->wall.column_base), "./img/column_base.xpm");
	import_img(data, &(data->wall.front_l), "./img/wall_corner_front_left.xpm");
	import_img(data, &(data->wall.front_r), "./img/wall_corner_front_righ.xpm");
	import_img(data, &(data->wall.top_right), "./img/wall_top_right.xpm");
	import_img(data, &(data->wall.top_left), "./img/wall_top_left.xpm");
	import_img(data, &(data->wall.corner_right), "./img/wall_corner_right.xpm");
	import_img(data, &(data->wall.corner_left), "./img/wall_corner_left.xpm");
	import_img(data, &(data->player.r.idle_0), "./img/64_knight_idle_r0.xpm");
	import_img(data, &(data->player.r.idle_1), "./img/64_knight_idle_r1.xpm");
	import_img(data, &(data->player.r.idle_2), "./img/64_knight_idle_r2.xpm");
	import_img(data, &(data->player.r.idle_3), "./img/64_knight_idle_r3.xpm");
	import_img(data, &(data->player.r.run_0), "./img/64_knight_run_r0.xpm");
	import_img(data, &(data->player.r.run_1), "./img/64_knight_run_r1.xpm");
	import_img(data, &(data->player.r.run_2), "./img/64_knight_run_r2.xpm");
	import_imgs_part3(data);
}

void	import_imgs(t_data *data)
{
	import_img(data, &(data->layer.front), "./img/empty.xpm");
	new_layer(data, &(data->layer.back));
	new_layer(data, &(data->layer.tmp));
	import_img(data, &(data->floor.f1), "./img/floor_1.xpm");
	import_img(data, &(data->floor.f2), "./img/floor_2.xpm");
	import_img(data, &(data->floor.f3), "./img/floor_3.xpm");
	import_img(data, &(data->floor.f4), "./img/floor_4.xpm");
	import_img(data, &(data->floor.f5), "./img/floor_5.xpm");
	import_img(data, &(data->floor.f6), "./img/floor_6.xpm");
	import_img(data, &(data->floor.f7), "./img/floor_7.xpm");
	import_img(data, &(data->floor.f8), "./img/floor_8.xpm");
	import_img(data, &(data->floor.start), "./img/start.xpm");
	import_img(data, &(data->wall.mid), "./img/wall_mid.xpm");
	import_img(data, &(data->wall.mid1), "./img/wall_mid_1.xpm");
	import_img(data, &(data->wall.mid3), "./img/wall_mid_3.xpm");
	import_img(data, &(data->wall.mid6), "./img/wall_mid_6.xpm");
	import_img(data, &(data->wall.mid61), "./img/wall_mid_61.xpm");
	import_img(data, &(data->wall.mid7), "./img/wall_mid_7.xpm");
	import_img(data, &(data->wall.mid8), "./img/wall_mid_8.xpm");
	import_img(data, &(data->wall.side_left), "./img/wall_side_mid_left.xpm");
	import_img(data, &(data->wall.side_right), "./img/wall_side_mid_right.xpm");
	import_img(data, &(data->wall.side_down_l), "./img/wall_side_l.xpm");
	import_img(data, &(data->wall.side_down_r), "./img/wall_side_r.xpm");
	import_imgs_part2(data);
}
