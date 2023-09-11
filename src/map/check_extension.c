/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:07:02 by jlanza            #+#    #+#             */
/*   Updated: 2023/03/21 14:45:52 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_extension(char *path)
{
	int	i;

	if (path == NULL || ft_strlen(path) <= 4)
		return (0);
	i = 0;
	while (path[i])
		i++;
	if (path[i - 5] == '/' || path[i - 4] != '.' || path[i - 3] != 'b'
		|| path[i - 2] != 'e' || path[i - 1] != 'r')
		return (0);
	return (1);
}
