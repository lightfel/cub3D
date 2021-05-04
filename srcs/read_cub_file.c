/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cub_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhikaru <nhikaru@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 15:25:24 by nhikaru           #+#    #+#             */
/*   Updated: 2021/05/03 17:24:39 by nhikaru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_texture_identifier(char *identifier)
{
	if (!ft_strncmp(identifier, "NO", 3)
		|| !ft_strncmp(identifier, "SO", 3)
		|| !ft_strncmp(identifier, "WE", 3)
		|| !ft_strncmp(identifier, "EA", 3)
		|| !ft_strncmp(identifier, "S", 2))
		return (true);
	return (false);
}

static bool	is_color_identifier(char *identifier)
{
	if (!ft_strncmp(identifier, "F", 2) || !ft_strncmp(identifier, "C", 2))
		return (true);
	return (false);
}

static bool	is_all_flag_true(t_file *p_cub)
{
	if (p_cub->resolution.flag
		&& p_cub->texture[NORTH].flag
		&& p_cub->texture[SOUTH].flag
		&& p_cub->texture[WEST].flag
		&& p_cub->texture[EAST].flag
		&& p_cub->texture[SPRITE].flag
		&& p_cub->color[FLOOR].flag
		&& p_cub->color[CEILLING].flag)
		return (true);
	return (false);
}

static void	read_line(t_file *p_cub, char *line, char **element)
{
	while (get_next_line(p_cub->fd, &line) == 1)
	{
		p_cub->status = 1;
		element = ft_split(line, ' ');
		if (!element)
			set_error(&p_cub->error, "An error happened by ft_split");
		else if (element[0] && !ft_strncmp(element[0], "R", 2))
			set_resolution(p_cub, element);
		else if (element[0] && is_texture_identifier(element[0]))
			set_texture_path(p_cub, element);
		else if (element[0] && is_color_identifier(element[0]))
			set_color(p_cub, element);
		else if (is_all_flag_true(p_cub))
			set_map(p_cub, line);
		else if (element[0] && is_map_line(p_cub, line))
			set_error(&p_cub->error, "Set all type before map");
		else if (element[0] || *line == ' ')
			set_error(&p_cub->error, "Invalid type identifier");
		safe_free_ptr((void **)&line);
		safe_free_ptr_array((void ***)&element);
		if (p_cub->error.flag)
			process_file_error(p_cub, p_cub->error.message);
	}
	safe_free_ptr((void **)&line);
}

void	read_cub_file(char *path, t_file *p_cub)
{
	p_cub->fd = open(path, O_RDONLY);
	if (p_cub->fd == -1)
		put_error_and_exit("Failed to open the file");
	p_cub->status = 0;
	read_line(p_cub, NULL, NULL);
	if (p_cub->status == 0)
		put_error_and_exit("An error happened by gnl");
	if (!p_cub->map.start || !is_all_flag_true(p_cub))
		set_error(&p_cub->error, "Invalid file format");
	else if (!p_cub->map.player)
		set_error(&p_cub->error, "Set player on the map");
	else
		flood_fill(p_cub, p_cub->map.pos_x, p_cub->map.pos_y);
	if (p_cub->error.flag)
		process_file_error(p_cub, p_cub->error.message);
	close(p_cub->fd);
}
