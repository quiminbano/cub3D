# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: corellan <corellan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 10:54:50 by corellan          #+#    #+#              #
#    Updated: 2023/04/27 14:58:12 by corellan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS = main.c cub3d_events.c cub3d_key_events.c check_arguments.c \
check_file_map.c utils.c check_textures.c check_floor_celling.c check_map.c \
check_map2.c utils2.c error.c check_map3.c

OBJS = main.o cub3d_events.o cub3d_key_events.o check_arguments.o \
check_file_map.o utils.o check_textures.o check_floor_celling.o check_map.o \
check_map2.o utils2.o error.o check_map3.o

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGL -framework AppKit

LIBFT = -Llibft -lft

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJS)

fclean:	clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re:	fclean	all
