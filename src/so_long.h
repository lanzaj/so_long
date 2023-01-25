/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:06:04 by jlanza            #+#    #+#             */
/*   Updated: 2023/01/25 16:30:57 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//# include <sys/types.h>
//# include <sys/stat.h>

/*include for open*/
# include <fcntl.h>

# include "../libft/libft.h"

typedef struct s_so_long
{
	t_list	*garbage;
}				t_so_long;

/*	ft_map	*/
int		count_number_of_lines(char **map);
int		count_char_in_map(char **map, char c);

/*	check	*/
void	check_map(char **map);
int		check_extension(char *path);
void	check_if_enclosed_in_walls(char **map);
void	check_map_flood(char **map);

/*	map error	*/
void	parse_map_error(int return_value);
void	check_map_error(int return_value, char **map);

char	**import_map(char *path);
char	**dup_map(char **map);
char	**free_map(char **tab);
void	print_map(char **map);

#endif
