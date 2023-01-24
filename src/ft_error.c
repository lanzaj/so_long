/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:17:08 by jlanza            #+#    #+#             */
/*   Updated: 2023/01/24 16:01:22 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(int return_value)
{
	if (return_value > 0)
		ft_putstr_fd("Error: ", 2);
	if (return_value == 1)
		ft_putendl_fd("There should be only one argument", 2);
	if (return_value == 2)
		ft_putendl_fd("File type should be '.ber'", 2);
	if (return_value == 3)
		ft_putendl_fd("Can't open file", 2);
	exit (return_value);
}
