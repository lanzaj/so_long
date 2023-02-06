/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:11:43 by jlanza            #+#    #+#             */
/*   Updated: 2023/02/06 13:16:48 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	parse_map_error(int return_value)
{
	if (return_value > 0)
		ft_putstr_fd("Error\n", 2);
	if (return_value == 1)
		ft_putendl_fd("There should be only one argument", 2);
	if (return_value == 2)
		ft_putendl_fd("File type should be '.ber'", 2);
	if (return_value == 3)
		ft_putendl_fd("Can't open file", 2);
	if (return_value == 4)
		ft_putendl_fd("Map file is empty", 2);
	exit (return_value);
}

void	check_map_error(int return_value, char **map)
{
	if (return_value > 0)
		ft_putstr_fd("Error\n", 2);
	if (return_value == 5)
		ft_putendl_fd("Map not rectangular", 2);
	if (return_value == 6)
		ft_putendl_fd("Map not enclosed in walls", 2);
	if (return_value == 7)
		ft_putendl_fd("Map should contain 1 starting position", 2);
	if (return_value == 8)
		ft_putendl_fd("Map should contain 1 exit", 2);
	if (return_value == 9)
		ft_putendl_fd("Map should contain at least 1 collectible", 2);
	if (return_value == 10)
		ft_putendl_fd("Map should only contain '0', '1', 'C', 'E' and 'P'", 2);
	if (return_value == 11)
		ft_putendl_fd("Map without valid path to finish", 2);
	if (return_value == 12)
		ft_putendl_fd("Map is too big", 2);
	free_map(map);
	exit (return_value);
}

void	lst_to_tab_error(t_list *lst, char **map, int fd)
{
	close(fd);
	ft_lstclear(&lst, &free);
	free_map(map);
	exit (1);
}

void	lst_to_tab_calloc_fail(t_list *lst, int fd)
{
	close(fd);
	ft_lstclear(&lst, &free);
	exit (1);
}
