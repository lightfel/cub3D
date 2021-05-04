/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhikaru <nhikaru@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 06:43:14 by nhikaru           #+#    #+#             */
/*   Updated: 2021/05/03 06:43:19 by nhikaru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	turn_left(t_player *p_player)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = p_player->dir_x;
	p_player->dir_x = p_player->dir_x * cos(p_player->rot_speed)
		+ p_player->dir_y * sin(p_player->rot_speed);
	p_player->dir_y = -old_dir_x * sin(p_player->rot_speed)
		+ p_player->dir_y * cos(p_player->rot_speed);
	old_plane_x = p_player->plane_x;
	p_player->plane_x = p_player->plane_x * cos(p_player->rot_speed)
		+ p_player->plane_y * sin(p_player->rot_speed);
	p_player->plane_y = -old_plane_x * sin(p_player->rot_speed)
		+ p_player->plane_y * cos(p_player->rot_speed);
}

void	turn_right(t_player *p_player)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = p_player->dir_x;
	p_player->dir_x = p_player->dir_x * cos(p_player->rot_speed)
		- p_player->dir_y * sin(p_player->rot_speed);
	p_player->dir_y = old_dir_x * sin(p_player->rot_speed)
		+ p_player->dir_y * cos(p_player->rot_speed);
	old_plane_x = p_player->plane_x;
	p_player->plane_x = p_player->plane_x * cos(p_player->rot_speed)
		- p_player->plane_y * sin(p_player->rot_speed);
	p_player->plane_y = old_plane_x * sin(p_player->rot_speed)
		+ p_player->plane_y * cos(p_player->rot_speed);
}
