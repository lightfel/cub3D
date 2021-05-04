/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhikaru <nhikaru@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 06:48:32 by nhikaru           #+#    #+#             */
/*   Updated: 2021/05/03 17:18:24 by nhikaru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_resolution_params_right(t_file *p_cub, char **element)
{
	if (!is_all_digit(element[1]) || !is_all_digit(element[2]))
		return (false);
	if (element[1][0] == '0' || element[2][0] == '0')
		return (false);
	p_cub->resolution.x = ft_atoi(element[1]);
	if (p_cub->resolution.x == -1 && element[1][0] != '-')
		p_cub->resolution.x = INT_MAX;
	p_cub->resolution.y = ft_atoi(element[2]);
	if (p_cub->resolution.y == -1 && element[2][0] != '-')
		p_cub->resolution.y = INT_MAX;
	return (true);
}

void	set_resolution(t_file *p_cub, char **element)
{
	int	split_num;

	if (p_cub->resolution.flag)
		return (set_error(&p_cub->error, "Only one resolution can be set"));
	split_num = get_split_num(element);
	if (split_num != 3 || (split_num == 3
			&& !(is_all_digit(element[1]) && is_all_digit(element[2]))))
		return (set_error(&p_cub->error, "Invalid resolution format"));
	if (!is_resolution_params_right(p_cub, element))
		return (set_error(&p_cub->error, "Invalid resolution format"));
	if (p_cub->resolution.x <= 0 || p_cub->resolution.y <= 0)
		return (set_error(&p_cub->error, "Invalid rendering resolution size"));
	p_cub->resolution.flag = true;
}
