/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:37:58 by feralves          #+#    #+#             */
/*   Updated: 2022/10/24 15:37:15 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/so_long.h"


void	put_image(t_vars *vars, void *img, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, img, x, y);
}

void	sprite_place(t_vars *vars, char **map)
{
	t_count	c;

	c.row = 0;
	c.collumn = 0;
	while (map[c.row])
	{
		c.collumn = 0;
		while (map[c.row][c.collumn])
		{
			if (map[c.row][c.collumn] == WALL)
				put_image(vars, vars->sprite.wall.img, c.collumn * PIXEL_SIZE, \
				c.row * PIXEL_SIZE);
			if (map[c.row][c.collumn] == COLLECTIBLE)
				put_image(vars, vars->sprite.item.img, c.collumn * PIXEL_SIZE, \
				c.row * PIXEL_SIZE);
			if (map[c.row][c.collumn] == ENDPOINT)
				put_image(vars, vars->sprite.endpoint.img, c.collumn * PIXEL_SIZE, \
				c.row * PIXEL_SIZE);
			if (map[c.row][c.collumn] == PLAYER)
				put_image(vars, vars->sprite.cavalinho.img, c.collumn * PIXEL_SIZE, \
				c.row * PIXEL_SIZE);
			c.collumn ++;
		}
		c.row ++;
	}
}
	
void	load_sprite(t_vars *vars, t_imagem *img, void *sprite)
{
	int		width;
	int		height;

	img->img = NULL;
	ft_printf("%p\n\n", img->img);
	img->img = mlx_xpm_file_to_image(vars->mlx, sprite, &width, &height);
	ft_printf("%p\n\n", img->img);
	if (img->img == NULL)
		ft_printf("Error loading img");
}

void	bananinha(t_vars *vars)
{
	load_sprite(vars, &(vars->sprite.cavalinho), SPRITE_CHAR);
	load_sprite(vars, &(vars->sprite.wall), SPRITE_WALL);
	load_sprite(vars, &(vars->sprite.item), SPRITE_ITEM);
	load_sprite(vars, &(vars->sprite.endpoint), SPRITE_EXIT);
//	load_sprite(vars, &(vars->sprite.floor), SPRITE_FLOOR);
}

void	open_game(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, PIXEL_SIZE * vars->fullmap->width, \
	PIXEL_SIZE * vars->fullmap->height, "so_long");
	mlx_hook(vars->win, 2, (1L << 0), esc_hook, vars);
	mlx_hook(vars->win, 17, (1L << 2), click_hook, vars);
	bananinha(vars);
//	load_sprite(vars, &(vars->sprite.wall), SPRITE_WALL);
	ft_printf_array(vars->fullmap->map);
	sprite_place(vars, vars->fullmap->map);
	mlx_loop(vars->mlx);
}
