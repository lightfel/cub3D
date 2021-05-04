/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhikaru <nhikaru@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 06:46:34 by nhikaru           #+#    #+#             */
/*   Updated: 2021/05/03 06:46:35 by nhikaru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_map(t_game *p_game, t_map *p_map)
{
	int	x;
	int	y;

	p_game->sprite.num = 0;
	y = 0;
	while (y < MAX_MAP_HEIGHT)
	{
		x = 0;
		while (x < MAX_MAP_WIDTH)
		{
			if (p_map->map[y][x] == 'P' || p_map->map[y][x] == ' ')
				p_game->map[y][x] = 0;
			else
			{
				if (p_map->map[y][x] == '2')
					p_game->sprite.num++;
				p_game->map[y][x] = p_map->map[y][x] - '0';
			}
			x++;
		}
		y++;
	}
}
