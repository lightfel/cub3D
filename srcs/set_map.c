/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhikaru <nhikaru@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:39:44 by nhikaru           #+#    #+#             */
/*   Updated: 2021/05/03 17:23:04 by nhikaru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_map_line(t_file *p_cub, char *line)
{
	int	i;
	int	space;

	i = 0;
	space = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && line[i] != '0'
			&& line[i] != '1' && line[i] != '2'
			&& line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'W' && line[i] != 'E')
			return (false);
		if (line[i] == ' ')
			space++;
		i++;
	}
	if (space == i)
		return (false);
	if (i < MAX_MAP_WIDTH)
		return (true);
	set_error(&p_cub->error, "Map is over max width");
	return (false);
}

static void	set_player_position(t_file *p_cub, int width)
{
	p_cub->map.player++;
	if (p_cub->map.player > 1)
		set_error(&p_cub->error, "Only one player can be set");
	p_cub->map.pos_x = width;
	p_cub->map.pos_y = p_cub->map.height;
	p_cub->map.dir = p_cub->map.map[p_cub->map.height][width];
}

static void	set_map_line(t_file *p_cub, char *line)
{
	int	width;

	if (p_cub->map.height < MAX_MAP_HEIGHT)
	{
		width = 0;
		while (line[width] != '\0' && !p_cub->error.flag)
		{
			p_cub->map.map[p_cub->map.height][width] = line[width];
			if (line[width] == 'N' || line[width] == 'S'
				|| line[width] == 'W' || line[width] == 'E')
				set_player_position(p_cub, width);
			width++;
		}
		p_cub->map.height++;
	}
	else
		set_error(&p_cub->error, "Map is over max height");
}

void	set_map(t_file *p_cub, char *line)
{
	if (!*line && (!p_cub->map.start || p_cub->map.end))
		return ;
	if (p_cub->map.end)
	{
		if (is_map_line(p_cub, line))
			return (set_error(&p_cub->error, "Only one map can be set"));
		else
			return (set_error(&p_cub->error, "Invalid file format"));
	}
	if (!p_cub->map.start)
	{
		if (is_map_line(p_cub, line))
			p_cub->map.start = true;
		else if (!p_cub->error.flag)
			return (set_error(&p_cub->error, "Invalid type identifier"));
		else
			return ;
	}
	if (!*line)
		p_cub->map.end = true;
	if (*line && is_map_line(p_cub, line))
		set_map_line(p_cub, line);
	else if (*line && !p_cub->error.flag)
		set_error(&p_cub->error, "Invalid map format");
}
