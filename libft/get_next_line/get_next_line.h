/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:38:11 by jlanza            #+#    #+#             */
/*   Updated: 2023/01/13 15:39:00 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);

int		pos_end_line(char *s);
char	*get_begin(char *s, int pos);
char	*get_end(char *src, char *dst, int pos);
int		ft_strlen2(const char *s);
char	*ft_strjoin_gnl(char *s1, char const *s2);

#endif
