/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhikaru <nhikaru@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 06:49:30 by nhikaru           #+#    #+#             */
/*   Updated: 2021/05/03 17:44:06 by nhikaru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	sort_sprites(t_sprite *p_sprite)
{
	t_info	tmp;
	int		i;
	int		j;

	i = 0;
	while (i < p_sprite->num)
	{
		j = 0;
		while (j < p_sprite->num - 1)
		{
			if (p_sprite->sprite[j].distance < p_sprite->sprite[j + 1].distance)
			{
				tmp = p_sprite->sprite[j];
				p_sprite->sprite[j] = p_sprite->sprite[j + 1];
				p_sprite->sprite[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void	calc_sprite(t_game *p_game,
		t_sprite *p_sprite, t_player *p_player, int i)
{
	p_sprite->x = p_sprite->sprite[i].x - p_player->pos_x;
	p_sprite->y = p_sprite->sprite[i].y - p_player->pos_y;
	p_sprite->inv_det = 1.0 / (p_player->plane_x * p_player->dir_y
			- p_player->dir_x * p_player->plane_y);
	p_sprite->transform_x = p_sprite->inv_det
		* (p_player->dir_y * p_sprite->x - p_player->dir_x * p_sprite->y);
	p_sprite->transform_y = p_sprite->inv_det
		* (-p_player->plane_y * p_sprite->x + p_player->plane_x * p_sprite->y);
	p_sprite->screen_x = (int)((p_game->image.width / 2)
			* (1 + p_sprite->transform_x / p_sprite->transform_y));
	p_sprite->height = (int)fabs(p_game->image.height / p_sprite->transform_y);
	p_sprite->drawstart_y = -p_sprite->height / 2 + p_game->image.height / 2;
	if (p_sprite->drawstart_y < 0)
		p_sprite->drawstart_y = 0;
	p_sprite->drawend_y = p_sprite->height / 2 + p_game->image.height / 2;
	if (p_sprite->drawend_y >= p_game->image.height)
		p_sprite->drawend_y = p_game->image.height - 1;
	p_sprite->width = (int)fabs(p_game->image.height / p_sprite->transform_y);
	p_sprite->drawstart_x = -p_sprite->width / 2 + p_sprite->screen_x;
	if (p_sprite->drawstart_x < 0)
		p_sprite->drawstart_x = 0;
	p_sprite->drawend_x = p_sprite->width / 2 + p_sprite->screen_x;
	if (p_sprite->drawend_x >= p_game->image.width)
		p_sprite->drawend_x = p_game->image.width - 1;
}

static void	draw_stripe(t_game *p_game, t_sprite *p_sprite, int x)
{
	int	y;
	int	d;

	y = p_sprite->drawstart_y;
	while (y < p_sprite->drawend_y)
	{
		d = y * 256 - p_game->image.height * 128 + p_sprite->height * 128;
		p_sprite->texture_y = ((d * p_game->texture.height[SPRITE])
				/ p_sprite->height) / 256;
		p_sprite->color = p_game->texture.texture[SPRITE]
		[p_game->texture.width[SPRITE]
			* p_sprite->texture_y + p_sprite->texture_x];
		if ((p_sprite->color & 0x00FFFFFF) != 0)
			put_pixel_to_image(&p_game->image, x, y, p_sprite->color);
		y++;
	}
}

static void	draw_a_sprite(t_game *p_game, t_sprite *p_sprite)
{
	int	x;

	x = p_sprite->drawstart_x;
	while (x < p_sprite->drawend_x)
	{
		p_sprite->texture_x = (int)((256 * (x
						- (-p_sprite->width / 2 + p_sprite->screen_x))
					* p_game->texture.width[SPRITE] / p_sprite->width) / 256);
		if (p_sprite->transform_y > 0 && x > 0 && x < p_game->image.width
			&& p_sprite->transform_y < p_sprite->zbuffer[x])
			draw_stripe(p_game, p_sprite, x);
		x++;
	}
}

void	draw_sprites(t_game *p_game, t_sprite *p_sprite, t_player *p_player)
{
	int	i;

	i = 0;
	while (i < p_sprite->num)
	{
		p_sprite->sprite[i].distance
			= pow(p_player->pos_x - p_sprite->sprite[i].x, 2)
			+ pow(p_player->pos_y - p_sprite->sprite[i].y, 2);
		i++;
	}
	sort_sprites(p_sprite);
	i = 0;
	while (i < p_sprite->num)
	{
		calc_sprite(p_game, p_sprite, p_player, i);
		draw_a_sprite(p_game, p_sprite);
		i++;
	}
}
