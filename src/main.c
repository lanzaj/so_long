/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:05:56 by jlanza            #+#    #+#             */
/*   Updated: 2024/04/23 17:27:14 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc > 2)
		parse_map_error(1);
	if (argc == 2)
		data.map.ptr = import_map(argv[1]);
	else
		data.map.ptr = import_map("./maps/valid/big_map.ber");
	check_map(data.map.ptr);
	init_data(&data);
	game_init(&data);
	return (0);
}
