#include "cub3d.h"

void	print_t_file(t_file *p_cub)
{
	printf("resolution.flag = %d\n", p_cub->resolution.flag);
	printf("resolution.x = %d\n", p_cub->resolution.x);
	printf("resolution.y = %d\n", p_cub->resolution.y);
	for (int i = 0; i < 5; i++)
	{
		printf("texture[%d].flag = %d\n", i, p_cub->texture[i].flag);
		printf("texture[%d].path = %s\n", i, p_cub->texture[i].path);
	}
	printf("color[FLOOR].flag = %d\n", p_cub->color[FLOOR].flag);
	printf("color[FLOOR].red = %d\n", p_cub->color[FLOOR].red);
	printf("color[FLOOR].green = %d\n", p_cub->color[FLOOR].green);
	printf("color[FLOOR].blue = %d\n", p_cub->color[FLOOR].blue);
	printf("color[FLOOR].rgb = %d\n", p_cub->color[FLOOR].rgb);
	printf("color[CEILLING].flag = %d\n", p_cub->color[CEILLING].flag);
	printf("color[CEILLING].red = %d\n", p_cub->color[CEILLING].red);
	printf("color[CEILLING].green = %d\n", p_cub->color[CEILLING].green);
	printf("color[CEILLING].blue = %d\n", p_cub->color[CEILLING].blue);
	printf("color[CEILLING].rgb = %d\n", p_cub->color[CEILLING].rgb);
	printf("map.start = %d\n", p_cub->map.start);
	printf("map.end = %d\n", p_cub->map.end);
	printf("map.height = %d\n", p_cub->map.height);
	printf("map.pos_x = %d\n", p_cub->map.pos_x);
	printf("map.pos_y = %d\n", p_cub->map.pos_y);
	printf("map.dir = %c\n", p_cub->map.dir);
	printf("map\n");
	for (int y = 0; y < MAX_MAP_HEIGHT; y++)
	{
		for (int x = 0; x < MAX_MAP_WIDTH; x++)
		{
			printf("%c", p_cub->map.map[y][x]);
		}
		printf("\n");
	}
	printf("error.flag = %d\n", p_cub->error.flag);
	printf("error.message = %s\n", p_cub->error.message);
}
/*
void	print_t_game(t_game *p_game)
{
	printf("player.pos_x = %f\n", p_game->player.pos_x);
	printf("player.pos_y = %f\n", p_game->player.pos_y);
	printf("player.dir_x = %f\n", p_game->player.dir_x);
	printf("player.dir_y = %f\n", p_game->player.dir_y);
	printf("player.plane_x = %f\n", p_game->player.plane_x);
	printf("player.plane_y = %f\n", p_game->player.plane_y);
	printf("player.move_speed = %f\n", p_game->player.move_speed);
	printf("player.rot_speed = %f\n", p_game->player.rot_speed);
	printf("window.win = %p\n", p_game->window.win);
	printf("window.width = %d\n", p_game->window.width);
	printf("window.height = %d\n", p_game->window.height);
	printf("image.img = %p\n", p_game->image.img);
	//printf("image.data = %p\n", p_game->image.data);
	printf("image.addr = %p\n", p_game->image.addr);
	printf("image.size_l = %d\n", p_game->image.size_l);
	printf("image.bits_per_pixel = %d\n", p_game->image.bits_per_pixel);
	printf("image.line_length = %d\n", p_game->image.line_length);
	printf("image.endian = %d\n", p_game->image.endian);
	printf("image.width = %d\n", p_game->image.width);
	printf("image.height = %d\n", p_game->image.height);
	printf("line.floor_color = %d\n", p_game->line.floor_color);
	printf("line.ceilling_color = %d\n", p_game->line.ceilling_color);
	for (int i = 0; i < 5; i++)
	{
		printf("texture.texture[%d] = %p\n", i, p_game->texture.texture[i]);
		printf("texture.width[%d] = %d\n", i, p_game->texture.width[i]);
		printf("texture.height[%d] = %d\n", i, p_game->texture.height[i]);
	}
	for (int y = 0; y < MAX_MAP_HEIGHT; y++)
	{
		for (int x = 0; x < MAX_MAP_WIDTH; x++)
		{
			printf("%d", p_game->map[y][x]);
		}
		printf("\n");
	}
	printf("sprite.num = %d\n", p_game->sprite.num);
}
*/
