/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhikaru <nhikaru@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 06:45:42 by nhikaru           #+#    #+#             */
/*   Updated: 2021/05/03 17:43:34 by nhikaru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_color_index(char *identifier)
{
	if (identifier[0] == 'F')
		return (FLOOR);
	else
		return (CEILLING);
}

static char	*get_multiple_error_msg(int index)
{
	if (index == FLOOR)
		return ("Only one floor color can be set");
	else
		return ("Only one ceilling color can be set");
}

static char	*get_format_error_msg(int index)
{
	if (index == FLOOR)
		return ("Invalid floor color format");
	else
		return ("Invalid ceilling color format");
}

static bool	is_rgb_params_right(t_file *p_cub,
		char **params, char **element, int index)
{
	if (count_comma(element[1]) != 2)
		return (false);
	if (!(is_all_digit(params[0])
			&& is_all_digit(params[1]) && is_all_digit(params[2])))
		return (false);
	if ((params[0][0] == '0' && params[0][1] != '\0')
		|| (params[1][0] == '0' && params[1][1] != '\0')
		|| (params[2][0] == '0' && params[2][1] != '\0'))
		return (false);
	p_cub->color[index].red = ft_atoi(params[0]);
	p_cub->color[index].green = ft_atoi(params[1]);
	p_cub->color[index].blue = ft_atoi(params[2]);
	if (p_cub->color[index].red < 0 || p_cub->color[index].red > 255)
		return (false);
	if (p_cub->color[index].green < 0 || p_cub->color[index].green > 255)
		return (false);
	if (p_cub->color[index].blue < 0 || p_cub->color[index].blue > 255)
		return (false);
	return (true);
}

void	set_color(t_file *p_cub, char **element)
{
	char	**params;
	int		index;
	int		split_num;

	index = get_color_index(element[0]);
	if (p_cub->color[index].flag)
		return (set_error(&p_cub->error, get_multiple_error_msg(index)));
	split_num = get_split_num(element);
	if (split_num != 2)
		return (set_error(&p_cub->error, get_format_error_msg(index)));
	params = ft_split(element[1], ',');
	if (!params)
		return (set_error(&p_cub->error, "An error happened by ft_split"));
	split_num = get_split_num(params);
	if (split_num != 3 || (split_num == 3
			&& !is_rgb_params_right(p_cub, params, element, index)))
	{
		safe_free_ptr_array((void ***)&params);
		return (set_error(&p_cub->error, get_format_error_msg(index)));
	}
	safe_free_ptr_array((void ***)&params);
	p_cub->color[index].rgb = p_cub->color[index].red * pow(256, 2)
		+ p_cub->color[index].green * 256 + p_cub->color[index].blue;
	p_cub->color[index].flag = true;
}
