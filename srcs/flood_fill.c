/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhikaru <nhikaru@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 06:46:49 by nhikaru           #+#    #+#             */
/*   Updated: 2021/05/03 06:46:51 by nhikaru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	flood_fill(t_file *p_cub, int x, int y)
{
	if (x < 0 || x >= MAX_MAP_WIDTH || y < 0 || y >= MAX_MAP_HEIGHT)
		return ;
	if ((x == 0 || x == MAX_MAP_WIDTH - 1 || y == 0 || y == MAX_MAP_HEIGHT - 1)
		&& p_cub->map.map[y][x] != '1')
		return (process_file_error(p_cub, "Map isn't surrounded by wall"));
	if (p_cub->map.map[y][x] == '1' || p_cub->map.map[y][x] == '2'
		|| p_cub->map.map[y][x] == 'P')
		return ;
	else if (p_cub->map.map[y][x] == ' ')
		return (process_file_error(p_cub, "Invalid map"));
	else
		p_cub->map.map[y][x] = 'P';
	flood_fill(p_cub, x, y - 1);
	flood_fill(p_cub, x, y + 1);
	flood_fill(p_cub, x - 1, y);
	flood_fill(p_cub, x + 1, y);
}
