/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhikaru <nhikaru@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 06:49:09 by nhikaru           #+#    #+#             */
/*   Updated: 2021/05/03 17:57:47 by nhikaru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdbool.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <math.h>
# include <mlx.h>
# include "key_linux.h"
# include "libft.h"
# include "get_next_line.h"

# include <stdio.h>

# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3
# define SPRITE 4
# define FLOOR 0
# define CEILLING 1
# define MAX_MAP_WIDTH 100
# define MAX_MAP_HEIGHT 100
# define HEADER_SIZE 54

typedef struct s_resolution
{
	bool	flag;
	int		x;
	int		y;
}		t_resolution;

typedef struct s_texture_path
{
	bool	flag;
	char	*path;
}		t_texture_path;

typedef struct s_color
{
	bool	flag;
	int		red;
	int		green;
	int		blue;
	int		rgb;
}		t_color;

typedef struct s_map
{
	bool	start;
	bool	end;
	int		height;
	char	map[MAX_MAP_HEIGHT][MAX_MAP_WIDTH];
	int		player;
	int		pos_x;
	int		pos_y;
	char	dir;
}		t_map;

typedef struct s_error
{
	bool	flag;
	char	*message;
}		t_error;

typedef struct s_file
{
	int				fd;
	int				status;
	t_resolution	resolution;
	t_texture_path	texture[5];
	t_color			color[2];
	t_map			map;
	t_error			error;
}		t_file;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move_speed;
	double	rot_speed;
}		t_player;

typedef struct s_window
{
	void	*win;
	int		width;
	int		height;
}		t_window;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		*data;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}		t_image;

typedef struct s_ray
{
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	perpwalldist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
}		t_ray;

typedef struct s_line
{
	t_ray	ray;
	int		height;
	int		drawstart;
	int		drawend;
	int		floor_color;
	int		ceilling_color;
	int		*color;
}		t_line;

typedef struct s_texture
{
	int		*texture[5];
	int		width[5];
	int		height[5];
	int		index;
	double	wall_x;
	int		x;
	int		y;
	double	step;
	double	pos;
}		t_texture;

typedef struct s_info
{
	double	x;
	double	y;
	double	distance;
}		t_info;

typedef struct s_sprite
{
	double	*zbuffer;
	int		num;
	t_info	*sprite;
	double	x;
	double	y;
	double	inv_det;
	double	transform_x;
	double	transform_y;
	int		screen_x;
	int		height;
	int		drawstart_x;
	int		drawstart_y;
	int		drawend_x;
	int		drawend_y;
	int		width;
	int		texture_x;
	int		texture_y;
	int		color;
}		t_sprite;

typedef struct s_game
{
	void		*mlx;
	t_player	player;
	t_window	window;
	t_image		image;
	t_line		line;
	t_texture	texture;
	t_sprite	sprite;
	t_error		error;
	int			map[MAX_MAP_HEIGHT][MAX_MAP_WIDTH];
}		t_game;

void	init_t_file(t_file *p_cub);
void	init_t_game(t_game *p_game, t_file *p_cub, int argc);
void	read_cub_file(char *path, t_file *p_cub);
void	set_resolution(t_file *p_cub, char **element);
void	set_texture_path(t_file *p_cub, char **element);
void	set_color(t_file *p_cub, char **element);
bool	is_map_line(t_file *p_cub, char *line);
void	set_map(t_file *p_cub, char *line);
void	flood_fill(t_file *p_cub, int x, int y);
void	load_player_info(t_player *p_player, t_map *p_map);
void	load_texture(t_game *p_game, t_file *p_cub);
void	load_map(t_game *p_game, t_map *p_map);
void	init_sprite(t_game *p_game);
int		put_image(t_game *p_game);
void	put_pixel_to_image(t_image *p_image, int x, int y, int color);
void	draw_image(t_game *p_game);
void	draw_sprites(t_game *p_game, t_sprite *p_sprite, t_player *p_player);
void	calc_line(t_game *p_game, int x);
void	calc_texture(t_game *p_game,
			t_line *p_line, t_ray *p_ray, t_texture *p_tex);
void	move_forward(t_game *p_game, t_player *p_player);
void	move_backward(t_game *p_game, t_player *p_player);
void	move_left(t_game *p_game, t_player *p_player);
void	move_right(t_game *p_game, t_player *p_player);
void	turn_left(t_player *p_player);
void	turn_right(t_player *p_player);
void	create_bitmap_image(t_game *p_game);
void	put_error_message(char *error_message);
void	put_error_and_exit(char *error_message);
void	set_error(t_error *p_error, char *error_message);
void	process_file_error(t_file *p_cub, char *error_message);
void	process_game_error(t_game *p_game, char *error_message);
void	safe_free_ptr(void **ptr);
void	safe_free_ptr_array(void ***ptr_array);
int		free_and_exit(t_game *p_game);
int		get_split_num(char **element);
bool	is_all_digit(char *str);
int		count_comma(char *str);

void	print_t_file(t_file *p_cub);
#endif
