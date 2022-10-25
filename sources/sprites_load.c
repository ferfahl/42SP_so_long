/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_load.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:38:09 by feralves          #+#    #+#             */
/*   Updated: 2022/10/25 10:40:12 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/so_long.h"

void	put_sprite(t_vars *vars, void *img, int x, int y)
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
				put_sprite(vars, vars->sprite.wall.img, c.collumn * PIXEL_SIZE, \
				c.row * PIXEL_SIZE);
			if (map[c.row][c.collumn] == COLLECTIBLE)
				put_sprite(vars, vars->sprite.item.img, c.collumn * PIXEL_SIZE, \
				c.row * PIXEL_SIZE);
			if (map[c.row][c.collumn] == ENDPOINT)
				put_sprite(vars, vars->sprite.endpoint.img, c.collumn * PIXEL_SIZE, \
				c.row * PIXEL_SIZE);
			if (map[c.row][c.collumn] == PLAYER)
				put_sprite(vars, vars->sprite.cavalinho.img, c.collumn * PIXEL_SIZE, \
				c.row * PIXEL_SIZE);
			c.collumn ++;
		}
		c.row ++;
	}
}
	
void	load_xpm(t_vars *vars, t_imagem *img, void *sprite)
{
	int		width;
	int		height;

	img->img = NULL;
//	ft_printf("%p\n\n", img->img);
	img->img = mlx_xpm_file_to_image(vars->mlx, sprite, &width, &height);
//	ft_printf("%p\n\n", img->img);
	if (img->img == NULL)
		ft_printf("Error loading img");
}

void	load_img(t_vars *vars)
{
	load_xpm(vars, &(vars->sprite.cavalinho), SPRITE_CHAR);
	load_xpm(vars, &(vars->sprite.wall), SPRITE_WALL);
	load_xpm(vars, &(vars->sprite.item), SPRITE_ITEM);
	load_xpm(vars, &(vars->sprite.endpoint), SPRITE_EXIT);
//	load_xpm(vars, &(vars->sprite.floor), SPRITE_FLOOR);
}
