/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhikaru <nhikaru@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 06:47:03 by nhikaru           #+#    #+#             */
/*   Updated: 2021/05/03 17:21:10 by nhikaru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	safe_free_ptr(void **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

static void	free_ptr_array(void **ptr_array)
{
	int	i;

	i = 0;
	while (ptr_array[i] != NULL)
	{
		safe_free_ptr(&ptr_array[i]);
		i++;
	}
	free(ptr_array);
}

void	safe_free_ptr_array(void ***ptr_array)
{
	free_ptr_array(*ptr_array);
	*ptr_array = NULL;
}

int	free_and_exit(t_game *p_game)
{
	int	i;

	if (p_game->window.win)
		mlx_destroy_window(p_game->mlx, p_game->window.win);
	if (p_game->image.img)
		mlx_destroy_image(p_game->mlx, p_game->image.img);
	if (p_game->mlx)
	{
		mlx_destroy_display(p_game->mlx);
		safe_free_ptr(&p_game->mlx);
	}
	safe_free_ptr((void **)&p_game->line.color);
	i = 0;
	while (i < 5)
		safe_free_ptr((void **)&p_game->texture.texture[i++]);
	safe_free_ptr((void **)&p_game->sprite.zbuffer);
	safe_free_ptr((void **)&p_game->sprite.sprite);
	exit(0);
	return (0);
}
