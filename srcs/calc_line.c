/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhikaru <nhikaru@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 06:47:27 by nhikaru           #+#    #+#             */
/*   Updated: 2021/05/03 17:37:05 by nhikaru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	calc_sidedist(t_ray *p_ray, t_player *p_player)
{
	if (p_ray->raydir_x < 0)
	{
		p_ray->step_x = -1;
		p_ray->sidedist_x
			= (p_player->pos_x - p_ray->map_x) * p_ray->deltadist_x;
	}
	else
	{
		p_ray->step_x = 1;
		p_ray->sidedist_x
			= (p_ray->map_x + 1.0 - p_player->pos_x) * p_ray->deltadist_x;
	}
	if (p_ray->raydir_y < 0)
	{
		p_ray->step_y = -1;
		p_ray->sidedist_y
			= (p_player->pos_y - p_ray->map_y) * p_ray->deltadist_y;
	}
	else
	{
		p_ray->step_y = 1;
		p_ray->sidedist_y
			= (p_ray->map_y + 1.0 - p_player->pos_y) * p_ray->deltadist_y;
	}
}

static void	calc_side(t_game *p_game, t_ray *p_ray)
{
	p_ray->hit = 0;
	while (p_ray->hit == 0)
	{
		if (p_ray->sidedist_x < p_ray->sidedist_y)
		{
			p_ray->sidedist_x += p_ray->deltadist_x;
			p_ray->map_x += p_ray->step_x;
			p_ray->side = 0;
		}
		else
		{
			p_ray->sidedist_y += p_ray->deltadist_y;
			p_ray->map_y += p_ray->step_y;
			p_ray->side = 1;
		}
		if (p_game->map[p_ray->map_y][p_ray->map_x] == 1)
			p_ray->hit = 1;
	}
}

static void	calc_ray(t_game *p_game, t_ray *p_ray, t_player *p_player, int x)
{
	p_ray->camera_x = 2 * x / (double)p_game->image.width - 1;
	p_ray->raydir_x = p_player->dir_x + p_player->plane_x * p_ray->camera_x;
	p_ray->raydir_y = p_player->dir_y + p_player->plane_y * p_ray->camera_x;
	p_ray->map_x = (int)p_player->pos_x;
	p_ray->map_y = (int)p_player->pos_y;
	p_ray->deltadist_x = fabs(1 / p_ray->raydir_x);
	p_ray->deltadist_y = fabs(1 / p_ray->raydir_y);
	calc_sidedist(p_ray, p_player);
	calc_side(p_game, p_ray);
	if (p_ray->side == 0)
		p_ray->perpwalldist = (p_ray->map_x - p_player->pos_x
				+ (1 - p_ray->step_x) / 2) / p_ray->raydir_x;
	else
		p_ray->perpwalldist = (p_ray->map_y - p_player->pos_y
				+ (1 - p_ray->step_y) / 2) / p_ray->raydir_y;
}

void	calc_line(t_game *p_game, int x)
{
	calc_ray(p_game, &p_game->line.ray, &p_game->player, x);
	p_game->line.height
		= (int)(p_game->image.height / p_game->line.ray.perpwalldist);
	if (p_game->line.height < 0)
		p_game->line.height = 0;
	p_game->line.drawstart
		= -p_game->line.height / 2 + p_game->image.height / 2;
	if (p_game->line.drawstart < 0)
		p_game->line.drawstart = 0;
	p_game->line.drawend = p_game->line.height / 2 + p_game->image.height / 2;
	if (p_game->line.drawend >= p_game->image.height)
		p_game->line.drawend = p_game->image.height - 1;
	calc_texture(p_game, &p_game->line, &p_game->line.ray, &p_game->texture);
	p_game->sprite.zbuffer[x] = p_game->line.ray.perpwalldist;
}
