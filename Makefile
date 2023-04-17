NAME = cub3d

SRCS = main.c

OBJS = main.o

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT = -Llibft -lft

all:	$(NAME)

$(NAME):	$(OBJS)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

clean:
	$(MAKE) clean -C ./libft 
	rm -f $(OBJS)

fclean:	clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re:	fclean	all
