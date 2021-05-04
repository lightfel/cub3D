/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhikaru <nhikaru@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 06:43:29 by nhikaru           #+#    #+#             */
/*   Updated: 2021/05/03 06:43:31 by nhikaru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_game *p_game, t_player *p_player)
{
	double	deltadist;

	deltadist = p_player->dir_x * p_player->move_speed;
	if (!p_game->map[(int)(p_player->pos_y)]
		[(int)(p_player->pos_x + deltadist)])
		p_player->pos_x += deltadist;
	deltadist = p_player->dir_y * p_player->move_speed;
	if (!p_game->map[(int)(p_player->pos_y + deltadist)]
		[(int)(p_player->pos_x)])
		p_player->pos_y += deltadist;
}

void	move_backward(t_game *p_game, t_player *p_player)
{
	double	deltadist;

	deltadist = -p_player->dir_x * p_player->move_speed;
	if (!p_game->map[(int)(p_player->pos_y)]
		[(int)(p_player->pos_x + deltadist)])
		p_player->pos_x += deltadist;
	deltadist = -p_player->dir_y * p_player->move_speed;
	if (!p_game->map[(int)(p_player->pos_y + deltadist)]
		[(int)(p_player->pos_x)])
		p_player->pos_y += deltadist;
}

void	move_right(t_game *p_game, t_player *p_player)
{
	double	norm;
	double	deltadist;

	norm = sqrt(pow(p_player->plane_x, 2) + pow(p_player->plane_y, 2));
	deltadist = p_player->plane_x / norm * p_player->move_speed;
	if (!p_game->map[(int)(p_player->pos_y)]
		[(int)(p_player->pos_x + deltadist)])
		p_player->pos_x += deltadist;
	deltadist = p_player->plane_y / norm * p_player->move_speed;
	if (!p_game->map[(int)(p_player->pos_y + deltadist)]
		[(int)(p_player->pos_x)])
		p_player->pos_y += deltadist;
}

void	move_left(t_game *p_game, t_player *p_player)
{
	double	norm;
	double	deltadist;

	norm = sqrt(pow(p_player->plane_x, 2) + pow(p_player->plane_y, 2));
	deltadist = -p_player->plane_x / norm * p_player->move_speed;
	if (!p_game->map[(int)(p_player->pos_y)]
		[(int)(p_player->pos_x + deltadist)])
		p_player->pos_x += deltadist;
	deltadist = -p_player->plane_y / norm * p_player->move_speed;
	if (!p_game->map[(int)(p_player->pos_y + deltadist)]
		[(int)(p_player->pos_x)])
		p_player->pos_y += deltadist;
}
