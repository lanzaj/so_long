/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:05:56 by jlanza            #+#    #+#             */
/*   Updated: 2023/01/24 16:50:50 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**free_map(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab[i]);
	free(tab);
	return (NULL);
}

int	main(int argc, char *argv[])
{
	char	**map;

	if (argc != 2)
		ft_error(1);
	map = import_map(argv[1]);
	ft_putstr_fd(map[0], 1);
	ft_putstr_fd(map[1], 1);
	ft_putstr_fd(map[2], 1);
	ft_putstr_fd(map[3], 1);
	ft_putstr_fd(map[4], 1);
	free_map(map);
}
