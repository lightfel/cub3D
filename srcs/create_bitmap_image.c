/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bitmap_image.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhikaru <nhikaru@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 06:49:40 by nhikaru           #+#    #+#             */
/*   Updated: 2021/05/03 17:07:16 by nhikaru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	write_bitmap_header(t_image *p_image, int fd, int filesize)
{
	unsigned char	header[HEADER_SIZE];

	ft_bzero(header, HEADER_SIZE);
	header[0] = 'B';
	header[1] = 'M';
	header[2] = filesize;
	header[3] = filesize >> 8;
	header[4] = filesize >> 16;
	header[5] = filesize >> 24;
	header[10] = 54;
	header[14] = 40;
	header[18] = p_image->width;
	header[19] = p_image->width >> 8;
	header[20] = p_image->width >> 16;
	header[21] = p_image->width >> 24;
	header[22] = p_image->height;
	header[23] = p_image->height >> 8;
	header[24] = p_image->height >> 16;
	header[25] = p_image->height >> 24;
	header[26] = 1;
	header[28] = 32;
	write(fd, header, HEADER_SIZE);
}

void	create_bitmap_image(t_game *p_game)
{
	int	fd;
	int	filesize;
	int	i;

	fd = open("./cub3D.bmp",
			O_WRONLY | O_CREAT | O_TRUNC, S_IREAD | S_IWRITE);
	if (fd == -1)
	{
		put_error_message("Failed to create bitmap image");
		free_and_exit(p_game);
	}
	filesize = HEADER_SIZE + (p_game->image.width
			* p_game->image.height * p_game->image.bits_per_pixel / 8);
	write_bitmap_header(&p_game->image, fd, filesize);
	draw_image(p_game);
	i = p_game->image.height - 1;
	while (i >= 0)
	{
		write(fd, p_game->image.addr + p_game->image.width * i * 4,
			p_game->image.width * 4);
		i--;
	}
	close(fd);
	free_and_exit(p_game);
}
