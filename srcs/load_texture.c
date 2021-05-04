/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhikaru <nhikaru@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 06:46:26 by nhikaru           #+#    #+#             */
/*   Updated: 2021/05/03 17:35:18 by nhikaru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_texture(int *texture, t_image *p_image)
{
	int	x;
	int	y;

	y = 0;
	while (y < p_image->height)
	{
		x = 0;
		while (x < p_image->width)
		{
			texture[p_image->width * y + x]
				= p_image->data[p_image->width * y + x];
			x++;
		}
		y++;
	}
}

static void	load_image(int index, t_game *p_game, t_file *p_cub)
{
	t_image	image;

	image.width = 0;
	image.height = 0;
	image.data = NULL;
	image.img = mlx_xpm_file_to_image(p_game->mlx,
			p_cub->texture[index].path, &image.width, &image.height);
	safe_free_ptr((void **)&p_cub->texture[index].path);
	if (!image.img)
		return (set_error(&p_game->error, "Invalid texture path"));
	image.data = (int *)mlx_get_data_addr(image.img,
			&image.bits_per_pixel, &image.line_length, &image.endian);
	if (!p_game->error.flag && !image.data)
		set_error(&p_game->error, "An error happened by mlx_get_data_addr");
	p_game->texture.texture[index]
		= malloc(sizeof(int) * image.width * image.height);
	if (!p_game->error.flag && !p_game->texture.texture[index])
		set_error(&p_game->error, "Failed to allocate memory in load_image");
	if (image.data)
		set_texture(p_game->texture.texture[index], &image);
	p_game->texture.width[index] = image.width;
	p_game->texture.height[index] = image.height;
	if (image.img)
		mlx_destroy_image(p_game->mlx, image.img);
}

void	load_texture(t_game *p_game, t_file *p_cub)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		p_game->texture.texture[i] = NULL;
		load_image(i, p_game, p_cub);
		i++;
	}
}
