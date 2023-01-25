/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:06:04 by jlanza            #+#    #+#             */
/*   Updated: 2023/01/25 02:08:29 by jlanza           ###   ########.fr       */
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

void	parse_error(int return_value);
void	verif_map_error(int return_value, char **map);

char	**import_map(char *path);
char	**free_map(char **tab);
void	check_map(char **map);

void	flood_check(char **map);
int		count_char_in_map(char **map, char c);


void	print_map(char **map);

#endif
