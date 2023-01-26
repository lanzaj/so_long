/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:06:04 by jlanza            #+#    #+#             */
/*   Updated: 2023/01/26 15:07:47 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//# include <sys/types.h>
//# include <sys/stat.h>

/* include for open */
# include <fcntl.h>

/* include math lib*/
# include <math.h>

/* include libft */
# include "../libft/libft.h"

/* include minilix */
# include "../minilibx-linux/mlx.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		heigh;
}				t_data;

typedef struct s_so_long
{
	t_list	*garbage;
}				t_so_long;

			/* COUNT IN MAP */
int		count_number_of_lines(char **map);
int		count_char_in_map(char **map, char c);

			/* CHECK */
void	check_map(char **map);
int		check_extension(char *path);
void	check_if_enclosed_in_walls(char **map);
void	check_map_flood(char **map);

			/* MAP ERROR */
void	parse_map_error(int return_value);
void	check_map_error(int return_value, char **map);

			/* DIVERS */
char	**import_map(char *path);
char	**dup_map(char **map);
char	**free_map(char **tab);
void	print_map(char **map);

#endif
