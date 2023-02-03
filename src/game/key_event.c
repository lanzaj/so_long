/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:19:25 by jlanza            #+#    #+#             */
/*   Updated: 2023/02/03 22:20:03 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_press(int keycode, void *data)
{
	t_data	*d;

	d = (t_data *)data;
	if (keycode == 65307)
		close_window(data);
	if (keycode == 119 || keycode == 65362)
		d->way.up = 1;
	if (keycode == 97 || keycode == 65361)
		d->way.left = 1;
	if (keycode == 115 || keycode == 65364)
		d->way.down = 1;
	if (keycode == 100 || keycode == 65363)
		d->way.right = 1;
	return (0);
}

int	key_release(int keycode, void *data)
{
	t_data	*d;

	d = (t_data *)data;
	if (keycode == 65307)
		close_window(data);
	if (keycode == 119 || keycode == 65362)
		d->way.up = 0;
	if (keycode == 97 || keycode == 65361)
		d->way.left = 0;
	if (keycode == 115 || keycode == 65364)
		d->way.down = 0;
	if (keycode == 100 || keycode == 65363)
		d->way.right = 0;
	return (0);
}
