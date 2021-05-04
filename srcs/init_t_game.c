/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_t_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhikaru <nhikaru@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 06:48:11 by nhikaru           #+#    #+#             */
/*   Updated: 2021/05/03 17:38:59 by nhikaru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_window(t_game *p_game,
	t_window *p_window, t_resolution *p_resolution)
{
	mlx_get_screen_size(p_game->mlx, &p_window->width, &p_window->height);
	if (p_resolution->x < p_window->width)
		p_window->width = p_resolution->x;
	if (p_resolution->y < p_window->height)
		p_window->height = p_resolution->y;
	p_window->win = NULL;
}

static void	init_image(t_game *p_game,
	t_image *p_image, t_resolution *p_resolution, int argc)
{
	p_image->width = p_game->window.width;
	p_image->height = p_game->window.height;
	if (argc == 3)
	{
		p_image->width = p_resolution->x;
		p_image->height = p_resolution->y;
	}
	p_image->img = mlx_new_image(p_game->mlx, p_image->width, p_image->height);
	if (!p_image->img && !p_game->error.flag)
		set_error(&p_game->error, "An error happened by mlx_new_image");
	if (p_image->img)
		p_image->addr = mlx_get_data_addr(p_image->img,
				&p_image->bits_per_pixel, &p_image->line_length,
				&p_image->endian);
	if (!p_game->error.flag && !p_image->addr)
		set_error(&p_game->error, "An error happened by mlx_get_data_addr");
}

static void	init_line(t_game *p_game, t_file *p_cub)
{
	p_game->line.floor_color = p_cub->color[FLOOR].rgb;
	p_game->line.ceilling_color = p_cub->color[CEILLING].rgb;
	p_game->line.color = ft_calloc(p_game->image.height, sizeof(int));
	if (!p_game->line.color && !p_game->error.flag)
		set_error(&p_game->error, "Failed to allocate memory in init_line");
}

void	init_t_game(t_game *p_game, t_file *p_cub, int argc)
{
	p_game->error.flag = false;
	p_game->error.message = NULL;
	p_game->mlx = mlx_init();
	if (!p_game->mlx)
		set_error(&p_game->error, "An error happened by mlx_init");
	load_player_info(&p_game->player, &p_cub->map);
	init_window(p_game, &p_game->window, &p_cub->resolution);
	init_image(p_game, &p_game->image, &p_cub->resolution, argc);
	init_line(p_game, p_cub);
	load_texture(p_game, p_cub);
	load_map(p_game, &p_cub->map);
	init_sprite(p_game);
	if (p_game->error.flag)
		process_game_error(p_game, p_game->error.message);
	if (argc != 3)
	{
		p_game->window.win = mlx_new_window(p_game->mlx,
				p_game->window.width, p_game->window.height, "cub3D");
		if (!p_game->window.win)
			process_game_error(p_game,
				"An error happened by mlx_new_window");
	}
}
