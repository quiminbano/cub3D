# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: corellan <corellan@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 10:54:50 by corellan          #+#    #+#              #
#    Updated: 2024/09/23 14:55:38 by corellan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS = main.c cub3d_events.c cub3d_key_events.c check_arguments.c \
check_file_map.c utils.c check_textures.c check_floor_ceiling.c check_map.c \
check_map2.c utils2.c error.c check_map3.c initialization.c game_loop.c \
render_functions.c put_pixel_in_image.c movement_functions.c \
movement_functions_2.c draw_window.c digital_differential_analyzer.c \
render_functions_helpers.c create_int_map.c process_textures.c \
insert_safety_movement_buffer.c determine_texture_pixel_colours_helpers.c

OBJS = main.o cub3d_events.o cub3d_key_events.o check_arguments.o \
check_file_map.o utils.o check_textures.o check_floor_ceiling.o check_map.o \
check_map2.o utils2.o error.o check_map3.o initialization.o game_loop.o \
render_functions.o put_pixel_in_image.o movement_functions.o \
movement_functions_2.o draw_window.o digital_differential_analyzer.o \
render_functions_helpers.o create_int_map.o process_textures.o \
insert_safety_movement_buffer.o determine_texture_pixel_colours_helpers.o

CC = cc

CFLAGS = -Wall -Wextra -Werror

ifeq ($(shell uname -s), Darwin)
	FOLDER = minilibx_macos
	INCLUDE = -I. -I$(FOLDER)
	MLX = -L$(FOLDER) -lmlx -framework OpenGL -framework AppKit
else
	FOLDER = minilibx_linux
	INCLUDE = -I. -I/usr/bin -I$(FOLDER)
	MLX = -L$(FOLDER) -lmlx -L/usr/lib -I$(FOLDER) -lXext -lX11 -lm -lz
endif

LIBFT = -Llibft -lft

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(MAKE) -C ./$(FOLDER)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJS)

fclean:	clean
	$(MAKE) fclean -C ./libft
	$(MAKE) clean -C ./$(FOLDER)
	rm -f $(NAME)

re:	fclean	all
