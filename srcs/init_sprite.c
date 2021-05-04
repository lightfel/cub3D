/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhikaru <nhikaru@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 06:47:48 by nhikaru           #+#    #+#             */
/*   Updated: 2021/05/03 17:18:04 by nhikaru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_sprite_coordinate(t_game *p_game)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (y < MAX_MAP_HEIGHT)
	{
		x = 0;
		while (x < MAX_MAP_WIDTH)
		{
			if (p_game->map[y][x] == 2)
			{
				p_game->sprite.sprite[i].x = (double)x + 0.5;
				p_game->sprite.sprite[i].y = (double)y + 0.5;
				i++;
			}
			x++;
		}
		y++;
	}
}

void	init_sprite(t_game *p_game)
{
	p_game->sprite.zbuffer = malloc(sizeof(double) * p_game->image.width);
	if (!p_game->sprite.zbuffer && !p_game->error.flag)
		set_error(&p_game->error, "Failed to allocate memory to zbuffer");
	p_game->sprite.sprite = malloc(sizeof(t_info) * p_game->sprite.num);
	if (!p_game->sprite.sprite && !p_game->error.flag)
		set_error(&p_game->error, "Failed to allocate memory to sprite");
	if (p_game->sprite.sprite)
		set_sprite_coordinate(p_game);
}
