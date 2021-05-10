/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhikaru <nhikaru@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 15:10:15 by nhikaru           #+#    #+#             */
/*   Updated: 2021/05/10 04:21:21 by nhikaru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	safe_free(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
	return (ERROR);
}

static int	store_tmp_in_save(char **save, char *tmp)
{
	*save = tmp;
	return (ERROR);
}

static ssize_t	process_save(char **line, char **save)
{
	ssize_t	id;
	char	*tmp;

	id = ft_strchr_id(*save, '\n');
	if (id == -1)
		return (CONTINUE);
	(*save)[id] = '\0';
	*line = ft_strjoin(*save, NULL);
	if (*line == NULL)
		return (ERROR);
	tmp = *save;
	*save = ft_strjoin(&(*save)[id + 1], NULL);
	if (*save == NULL)
	{
		*save = tmp;
		return (ERROR);
	}
	safe_free(&tmp);
	return (SUCCESS);
}

static ssize_t	process_read(int fd, char **line, char **save, char *buf)
{
	ssize_t	rc;
	ssize_t	ret_flag;
	char	*tmp;

	rc = read(fd, buf, BUFFER_SIZE);
	while (rc != ERROR)
	{
		buf[rc] = '\0';
		if (rc == 0)
			return (case_zero(line, save));
		tmp = *save;
		*save = ft_strjoin(*save, buf);
		if (*save == NULL)
			return (store_tmp_in_save(save, tmp));
		safe_free(&tmp);
		ret_flag = process_save(line, save);
		if (ret_flag != CONTINUE)
			return (ret_flag);
		rc = read(fd, buf, BUFFER_SIZE);
	}
	return (ERROR);
}

int	get_next_line(int fd, char **line)
{
	ssize_t		ret_flag;
	char		*buf;
	static char	*save;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (safe_free(&save));
	*line = NULL;
	buf = NULL;
	ret_flag = process_save(line, &save);
	if (ret_flag == CONTINUE)
	{
		buf = malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
		if (buf == NULL)
			return (safe_free(&save));
		ret_flag = process_read(fd, line, &save, buf);
	}
	if (ret_flag != SUCCESS)
		safe_free(&save);
	safe_free(&buf);
	return (ret_flag);
}
