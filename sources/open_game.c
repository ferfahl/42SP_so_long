/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:37:58 by feralves          #+#    #+#             */
/*   Updated: 2022/10/24 13:35:08 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/so_long.h"

void	load_sprite(t_vars *vars, void *sprite, int x, int y)
{
	int		width;
	int		height;

	vars->img = mlx_xpm_file_to_image(vars->mlx, sprite, &width, &height);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, x, y);
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
				load_sprite(vars, SPRITE_WALL, c.collumn * PIXEL_SIZE, \
				c.row * PIXEL_SIZE);
			if (map[c.row][c.collumn] == COLLECTIBLE)
				load_sprite(vars, SPRITE_COLLECTIBLE, c.collumn * PIXEL_SIZE, \
				c.row * PIXEL_SIZE);
			if (map[c.row][c.collumn] == ENDPOINT)
				load_sprite(vars, SPRITE_EXIT, c.collumn * PIXEL_SIZE, \
				c.row * PIXEL_SIZE);
			if (map[c.row][c.collumn] == PLAYER)
				load_sprite(vars, SPRITE_CHAR, c.collumn * PIXEL_SIZE, \
				c.row * PIXEL_SIZE);
			c.collumn ++;
		}
		c.row ++;
	}
}

void	open_game(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, PIXEL_SIZE * vars->fullmap->width, \
	PIXEL_SIZE * vars->fullmap->height, "so_long");
	mlx_hook(vars->win, 2, (1L << 0), esc_hook, vars);
	mlx_hook(vars->win, 17, (1L << 2), click_hook, vars);
	ft_printf_array(vars->fullmap->map);
	sprite_place(vars, vars->fullmap->map);
	mlx_loop(vars->mlx);
}
