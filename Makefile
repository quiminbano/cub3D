# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpoho <tpoho@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 10:54:50 by corellan          #+#    #+#              #
#    Updated: 2023/04/27 15:30:49 by tpoho            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS = main.c cub3d_events.c cub3d_key_events.c initialization.c game_loop.c \
		render_functions.c put_pixel_in_image.c movement_functions.c \
		movement_functions_2.c draw_window.c digital_differential_analyzer.c \
		render_functions_helpers.c

OBJS = main.o cub3d_events.o cub3d_key_events.o initialization.o game_loop.o \
		render_functions.o put_pixel_in_image.o movement_functions.o \
		movement_functions_2.o draw_window.o digital_differential_analyzer.o \
		render_functions_helpers.o

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLX = -lmlx -framework OpenGL -framework AppKit

LIBFT = -Llibft -lft

all:	$(NAME)

$(NAME):	$(OBJS)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(MLX) -o $(NAME)

clean:
	$(MAKE) clean -C ./libft 
	rm -f $(OBJS)

fclean:	clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re:	fclean	all
