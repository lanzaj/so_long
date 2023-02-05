/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr_of_mouvement.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:26:12 by jlanza            #+#    #+#             */
/*   Updated: 2023/02/05 01:23:01 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	put_digit(t_data *data, int n, int x)
{
	if (n == 0)
		put_img_to_tmp(data, &(data->digit.d_0), x, 16);
	if (n == 1)
		put_img_to_tmp(data, &(data->digit.d_1), x, 16);
	if (n == 2)
		put_img_to_tmp(data, &(data->digit.d_2), x, 16);
	if (n == 3)
		put_img_to_tmp(data, &(data->digit.d_3), x, 16);
	if (n == 4)
		put_img_to_tmp(data, &(data->digit.d_4), x, 16);
	if (n == 5)
		put_img_to_tmp(data, &(data->digit.d_5), x, 16);
	if (n == 6)
		put_img_to_tmp(data, &(data->digit.d_6), x, 16);
	if (n == 7)
		put_img_to_tmp(data, &(data->digit.d_7), x, 16);
	if (n == 8)
		put_img_to_tmp(data, &(data->digit.d_8), x, 16);
	if (n == 9)
		put_img_to_tmp(data, &(data->digit.d_9), x, 16);
}

void	put_nbr_of_mouvement(t_data *data, int n)
{
	int	x;

	x = data->width - 44;
	while (n >= 10)
	{
		put_digit(data, n % 10, x);
		x -= 32;
		n = n / 10;
	}
	put_digit(data, n % 10, x);
}
