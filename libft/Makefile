# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 15:24:20 by jlanza            #+#    #+#              #
#    Updated: 2023/01/13 16:04:47 by jlanza           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	ft_is/ft_isalpha.c \
		ft_is/ft_isdigit.c \
		ft_is/ft_isalnum.c \
		ft_is/ft_isascii.c \
		ft_is/ft_isprint.c \
		ft_str/ft_strlen.c \
		ft_str/ft_strlcpy.c \
		ft_str/ft_strlcat.c \
		ft_str/ft_strchr.c \
		ft_str/ft_strrchr.c \
		ft_str/ft_strncmp.c \
		ft_str/ft_strnstr.c \
		ft_str/ft_strdup.c \
		ft_str/ft_strjoin.c \
		ft_str/ft_strtrim.c \
		ft_str/ft_strmapi.c \
		ft_str/ft_striteri.c \
		ft_str/ft_substr.c \
		ft_str/ft_toupper.c \
		ft_str/ft_tolower.c \
		ft_str/ft_itoa.c \
		ft_str/ft_atoi.c \
		ft_str/ft_split.c \
		ft_mem/ft_bzero.c \
		ft_mem/ft_calloc.c \
		ft_mem/ft_memset.c \
		ft_mem/ft_memcpy.c \
		ft_mem/ft_memmove.c \
		ft_mem/ft_memchr.c \
		ft_mem/ft_memcmp.c \
		ft_put/ft_putchar_fd.c \
		ft_put/ft_putstr_fd.c \
		ft_put/ft_putendl_fd.c \
		ft_put/ft_putnbr_fd.c \
		ft_lst/ft_lstadd_front.c \
		ft_lst/ft_lstnew.c \
		ft_lst/ft_lstsize.c \
		ft_lst/ft_lstlast.c \
		ft_lst/ft_lstadd_back.c \
		ft_lst/ft_lstdelone.c \
		ft_lst/ft_lstclear.c \
		ft_lst/ft_lstiter.c \
		ft_lst/ft_lstmap.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		ft_printf/ft_printf.c \
		ft_printf/ft_printf_arg.c \
		ft_printf/ft_printf_arg2.c

OBJ = ${SRC:.c=.o}

AR = ar rcs
NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rm -f
HEADER =	libft.h \
			get_next_line/get_next_line.h \
			ft_printf/ft_printf.h

.c.o: $(SRC)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ) $(HEADER)
	$(AR) $(NAME) $(OBJ)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
