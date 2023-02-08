/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_windows.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:29:38 by jlanza            #+#    #+#             */
/*   Updated: 2023/02/08 12:33:06 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_window(t_data *data)
{
	int	i;

	i = 0;
	while (i < 124)
	{
		if (data->img_tab[i] != 0)
			mlx_destroy_image(data->mlx, data->img_tab[i]);
		i++;
	}
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_map(data->map.ptr);
	exit(0);
}

int	close_window_error(t_data *data)
{
	int	i;

	i = 0;
	while (i < 124)
	{
		if (data->img_tab[i] != 0)
			mlx_destroy_image(data->mlx, data->img_tab[i]);
		i++;
	}
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_map(data->map.ptr);
	ft_putendl_fd("Error\nNot enough memory", 2);
	exit(1);
}
