/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhikaru <nhikaru@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 15:11:38 by nhikaru           #+#    #+#             */
/*   Updated: 2021/05/10 04:27:07 by nhikaru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	case_zero(char **line, char **save)
{
	*line = ft_strjoin(*save, NULL);
	if (*line == NULL)
		return (ERROR);
	return (0);
}
