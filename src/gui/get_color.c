/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 00:57:34 by jlanza            #+#    #+#             */
/*   Updated: 2023/02/04 00:58:01 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

unsigned char	get_t(int trgb)
{
	return (((unsigned char *)&trgb)[3]);
}

int	get_color(t_img *xpm, int x, int y)
{
	if (x < 0 || x >= xpm->width || y < 0 || y >= xpm->height)
		return (-1);
	return (*(int *)(xpm->addr + (x * (xpm->bits_per_pixel / 8)
			+ y * xpm->line_length)));
}
