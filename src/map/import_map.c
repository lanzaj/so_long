/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:27:52 by jlanza            #+#    #+#             */
/*   Updated: 2023/02/02 18:27:03 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static t_list	*fd_to_lst(int fd)
{
	t_list	*lst;
	char	*line;

	lst = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		ft_lstadd_back(&lst, ft_lstnew(line));
		line = get_next_line(fd);
	}
	return (lst);
}

static void	trim_backslash_n(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}
}

static	char	**lst_to_tab(t_list *lst)
{
	int		i;
	char	**map;
	t_list	*current;

	if (lst == NULL)
		parse_map_error(4);
	map = ft_calloc(ft_lstsize(lst) + 2, sizeof(*map));
	current = lst;
	i = 0;
	while (current != NULL)
	{
		map[i] = ft_strdup(current->content);
		trim_backslash_n(map[i]);
		current = current->next;
		i++;
	}
	ft_lstclear(&lst, &free);
	return (map);
}

static char	**fd_to_map(int fd)
{
	t_list	*lst;
	char	**map;

	lst = fd_to_lst(fd);
	map = lst_to_tab(lst);
	return (map);
}

char	**import_map(char *path)
{
	char	**map;
	int		fd;

	map = NULL;
	if (!check_extension(path))
		parse_map_error(2);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		parse_map_error(3);
	map = fd_to_map(fd);
	close(fd);
	return (map);
}
