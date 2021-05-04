/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhikaru <nhikaru@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 06:47:39 by nhikaru           #+#    #+#             */
/*   Updated: 2021/05/03 17:20:55 by nhikaru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_texture_num(t_ray *p_ray, t_texture *p_texture)
{
	if (p_ray->side == 0 && p_ray->raydir_x > 0)
		p_texture->index = WEST;
	else if (p_ray->side == 0 && p_ray->raydir_x < 0)
		p_texture->index = EAST;
	else if (p_ray->side == 1 && p_ray->raydir_y > 0)
		p_texture->index = NORTH;
	else if (p_ray->side == 1 && p_ray->raydir_y < 0)
		p_texture->index = SOUTH;
}

void	calc_texture(t_game *p_game,
		t_line *p_line, t_ray *p_ray, t_texture *p_tex)
{
	int	y;

	set_texture_num(p_ray, p_tex);
	if (p_ray->side == 0)
		p_tex->wall_x = p_game->player.pos_y
			+ p_ray->perpwalldist * p_ray->raydir_y;
	else
		p_tex->wall_x = p_game->player.pos_x
			+ p_ray->perpwalldist * p_ray->raydir_x;
	p_tex->wall_x -= floor(p_tex->wall_x);
	p_tex->x = (int)(p_tex->wall_x * (double)p_tex->width[p_tex->index]);
	if (p_tex->index == EAST || p_tex->index == NORTH)
		p_tex->x = p_tex->width[p_tex->index] - p_tex->x - 1;
	p_tex->step = 1.0 * p_tex->height[p_tex->index] / p_line->height;
	p_tex->pos = (p_line->drawstart - p_game->image.height / 2
			+ p_line->height / 2) * p_tex->step;
	y = p_line->drawstart;
	while (y < p_line->drawend)
	{
		p_tex->y = (int)p_tex->pos & (p_tex->height[p_tex->index] - 1);
		p_tex->pos += p_tex->step;
		p_line->color[y] = p_tex->texture[p_tex->index]
		[p_tex->height[p_tex->index] * p_tex->y + p_tex->x];
		y++;
	}
}
