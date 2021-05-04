/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhikaru <nhikaru@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 06:49:20 by nhikaru           #+#    #+#             */
/*   Updated: 2021/05/03 17:24:19 by nhikaru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel_to_image(t_image *p_image, int x, int y, int color)
{
	char	*pixel;

	pixel = p_image->addr
		+ (y * p_image->line_length + x * (p_image->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

static void	draw_line_to_image(t_image *p_image, t_line *p_line, int x)
{
	int	y;

	y = 0;
	while (y < p_line->drawstart)
	{
		put_pixel_to_image(p_image, x, y, p_line->ceilling_color);
		y++;
	}
	while (y <= p_line->drawend)
	{
		put_pixel_to_image(p_image, x, y, p_line->color[y]);
		y++;
	}
	while (y < p_image->height)
	{
		put_pixel_to_image(p_image, x, y, p_line->floor_color);
		y++;
	}
}

void	draw_image(t_game *p_game)
{
	int	x;

	x = 0;
	while (x < p_game->image.width)
	{
		calc_line(p_game, x);
		draw_line_to_image(&p_game->image, &p_game->line, x);
		x++;
	}
	draw_sprites(p_game, &p_game->sprite, &p_game->player);
}
