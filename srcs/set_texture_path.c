/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhikaru <nhikaru@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 06:45:17 by nhikaru           #+#    #+#             */
/*   Updated: 2021/05/03 17:44:31 by nhikaru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_texture_path_index(char *identifier)
{
	if (identifier[0] == 'N')
		return (NORTH);
	else if (identifier[0] == 'S' && identifier[1] == 'O')
		return (SOUTH);
	else if (identifier[0] == 'W')
		return (WEST);
	else if (identifier[0] == 'E')
		return (EAST);
	else
		return (SPRITE);
}

static char	*get_multiple_error_msg(int index)
{
	if (index == NORTH)
		return ("Only one north texture can be set");
	else if (index == SOUTH)
		return ("Only one south texture can be set");
	else if (index == WEST)
		return ("Only one west texture can be set");
	else if (index == EAST)
		return ("Only one east texture can be set");
	else
		return ("Only one sprite texture can be set");
}

static char	*get_format_error_msg(int index)
{
	if (index == NORTH)
		return ("Invalid north texture format");
	else if (index == SOUTH)
		return ("Invalid south texture format");
	else if (index == WEST)
		return ("Invalid west texture format");
	else if (index == EAST)
		return ("Invalid east texture format");
	else
		return ("Invalid sprite texture format");
}

void	set_texture_path(t_file *p_cub, char **element)
{
	int		index;
	int		split_num;
	char	*path;

	index = get_texture_path_index(element[0]);
	if (p_cub->texture[index].flag)
		return (set_error(&p_cub->error, get_multiple_error_msg(index)));
	split_num = get_split_num(element);
	if (split_num != 2)
		return (set_error(&p_cub->error, get_format_error_msg(index)));
	path = ft_strdup(element[1]);
	if (!path)
		return (set_error(&p_cub->error, "An error happened by ft_strdup"));
	p_cub->texture[index].path = path;
	p_cub->texture[index].flag = true;
}
