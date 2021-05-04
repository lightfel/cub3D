/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_t_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhikaru <nhikaru@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 06:48:03 by nhikaru           #+#    #+#             */
/*   Updated: 2021/05/03 17:23:24 by nhikaru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_resolution(t_resolution *p_resolution)
{
	p_resolution->flag = false;
	p_resolution->x = 0;
	p_resolution->y = 0;
}

static void	init_texture_path(t_texture_path *p_texture)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		p_texture[i].flag = false;
		p_texture[i].path = NULL;
		i++;
	}
}

static void	init_color(t_color *p_color)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		p_color[i].flag = false;
		p_color[i].red = 0;
		p_color[i].green = 0;
		p_color[i].blue = 0;
		p_color[i].rgb = 0;
		i++;
	}
}

static void	init_map(t_map *p_map)
{
	int	x;
	int	y;

	y = 0;
	while (y < MAX_MAP_HEIGHT)
	{
		x = 0;
		while (x < MAX_MAP_WIDTH)
		{
			p_map->map[y][x] = '0';
			x++;
		}
		y++;
	}
	p_map->start = false;
	p_map->end = false;
	p_map->height = 0;
	p_map->player = 0;
	p_map->pos_x = 0;
	p_map->pos_y = 0;
	p_map->dir = '\0';
}

void	init_t_file(t_file *p_cub)
{
	p_cub->status = 0;
	init_resolution(&p_cub->resolution);
	init_texture_path(p_cub->texture);
	init_color(p_cub->color);
	init_map(&p_cub->map);
	p_cub->error.flag = false;
	p_cub->error.message = NULL;
}
