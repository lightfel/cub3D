/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhikaru <nhikaru@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 06:48:22 by nhikaru           #+#    #+#             */
/*   Updated: 2021/05/03 17:07:49 by nhikaru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_dir(t_player *p_player, double dir_x, double dir_y)
{
	p_player->dir_x = dir_x;
	p_player->dir_y = dir_y;
}

static void	set_plane(t_player *p_player, double plane_x, double plane_y)
{
	p_player->plane_x = plane_x;
	p_player->plane_y = plane_y;
}

void	load_player_info(t_player *p_player, t_map *p_map)
{
	p_player->pos_x = (double)p_map->pos_x + 0.5;
	p_player->pos_y = (double)p_map->pos_y + 0.5;
	if (p_map->dir == 'N')
	{
		set_dir(p_player, 0.0, -1.0);
		set_plane(p_player, 0.66, 0.0);
	}
	else if (p_map->dir == 'S')
	{
		set_dir(p_player, 0.0, 1.0);
		set_plane(p_player, -0.66, 0.0);
	}
	else if (p_map->dir == 'W')
	{
		set_dir(p_player, -1.0, 0.0);
		set_plane(p_player, 0.0, -0.66);
	}
	else if (p_map->dir == 'E')
	{
		set_dir(p_player, 1.0, 0.0);
		set_plane(p_player, 0.0, 0.66);
	}
	p_player->move_speed = 0.5;
	p_player->rot_speed = 0.05;
}
