/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhikaru <nhikaru@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 06:46:17 by nhikaru           #+#    #+#             */
/*   Updated: 2021/05/03 17:23:45 by nhikaru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_file_extension_cub(char *path)
{
	size_t	len;

	len = ft_strlen(path);
	if (len > 4 && *(path + len - 5) != '/'
		&& !ft_strncmp(path + len - 4, ".cub", 5))
		return (true);
	return (false);
}

static bool	is_command_line_arguments_valid(int argc, char **argv)
{
	if ((argc == 2 || (argc == 3 && !ft_strncmp(argv[2], "--save", 7)))
		&& is_file_extension_cub(argv[1]))
		return (true);
	if (argc == 1 || (argc >= 2 && !is_file_extension_cub(argv[1])))
		put_error_message("The second arguments must be a cub file path");
	if (argc >= 3)
	{
		if (ft_strncmp(argv[2], "--save", 7))
			put_error_message("The third arguments must be \"--save\"");
		if (argc > 3)
			put_error_message("Too many command line arguments");
	}
	return (false);
}

int	put_image(t_game *p_game)
{
	draw_image(p_game);
	mlx_put_image_to_window(p_game->mlx,
		p_game->window.win, p_game->image.img, 0, 0);
	return (0);
}

static int	key_press(int key, t_game *p_game)
{
	if (key == K_W || key == K_UP)
		move_forward(p_game, &p_game->player);
	if (key == K_S || key == K_DOWN)
		move_backward(p_game, &p_game->player);
	if (key == K_D)
		move_right(p_game, &p_game->player);
	if (key == K_A)
		move_left(p_game, &p_game->player);
	if (key == K_RIGHT)
		turn_right(&p_game->player);
	if (key == K_LEFT)
		turn_left(&p_game->player);
	if (key == K_ESC)
		free_and_exit(p_game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_file	cub;
	t_game	game;

	if (!is_command_line_arguments_valid(argc, argv))
		return (1);
	init_t_file(&cub);
	read_cub_file(argv[1], &cub);
	init_t_game(&game, &cub, argc);
	if (argc == 3)
		create_bitmap_image(&game);
	mlx_loop_hook(game.mlx, put_image, &game);
	mlx_hook(game.window.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.window.win, 33, 1L << 17, free_and_exit, &game);
	mlx_loop(game.mlx);
	return (0);
}
