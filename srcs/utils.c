/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhikaru <nhikaru@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 06:46:05 by nhikaru           #+#    #+#             */
/*   Updated: 2021/05/03 06:46:06 by nhikaru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_split_num(char **element)
{
	int	i;

	if (element == NULL)
		return (0);
	i = 0;
	while (element[i])
		i++;
	return (i);
}

bool	is_all_digit(char *str)
{
	int	i;

	if (str[0] == '\0')
		return (false);
	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

int	count_comma(char *str)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ',')
			comma++;
		i++;
	}
	return (comma);
}
