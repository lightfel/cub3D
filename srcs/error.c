/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhikaru <nhikaru@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 06:47:13 by nhikaru           #+#    #+#             */
/*   Updated: 2021/05/03 06:47:15 by nhikaru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_error_message(char *error_message)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(error_message, STDERR_FILENO);
}

void	put_error_and_exit(char *error_message)
{
	put_error_message(error_message);
	exit(1);
}

void	set_error(t_error *p_error, char *error_message)
{
	p_error->flag = true;
	p_error->message = error_message;
}

void	process_file_error(t_file *p_cub, char *error_message)
{
	int	i;

	if (p_cub->status == 1)
		get_next_line(p_cub->fd, NULL);
	i = 0;
	while (i < 5)
	{
		safe_free_ptr((void **)&p_cub->texture[i].path);
		i++;
	}
	put_error_message(error_message);
	close(p_cub->fd);
	exit(1);
}

void	process_game_error(t_game *p_game, char *error_message)
{
	put_error_message(error_message);
	free_and_exit(p_game);
}
