CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCDIR = ./includes
FTDIR = ./libft
MLXDIR = ./minilibx-linux
NAME = cub3D
OBJS = srcs/calc_line.o srcs/calc_texture.o srcs/create_bitmap_image.o\
	srcs/draw_image.o srcs/draw_sprites.o srcs/error.o srcs/flood_fill.o\
	srcs/free.o srcs/get_next_line.o srcs/get_next_line_utils.o\
	srcs/init_sprite.o srcs/init_t_file.o srcs/init_t_game.o\
	srcs/load_map.o srcs/load_player_info.o srcs/load_texture.o\
	srcs/main.o srcs/move.o srcs/read_cub_file.o srcs/set_color.o\
	srcs/set_map.o srcs/set_resolution.o srcs/set_texture_path.o\
	srcs/turn.o srcs/utils.o

$(NAME): $(OBJS)
	$(MAKE) -C $(FTDIR)
	$(MAKE) -C $(MLXDIR)
	$(CC) $(CFLAGS) $(OBJS) -L$(MLXDIR) -lmlx -lXext -lX11 -lm -I$(MLXDIR) -L$(FTDIR) -lft -I$(FTDIR) -I$(INCDIR) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -I$(INCDIR) -I$(FTDIR) -I$(MLXDIR) -c $< -o $*.o

all: $(NAME)

clean:
	$(MAKE) -C $(FTDIR) clean
	$(MAKE) -C $(MLXDIR) clean
	rm -f $(OBJS) cub3D.bmp

fclean: clean
	$(MAKE) -C $(FTDIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
