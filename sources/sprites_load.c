/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_load.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:38:09 by feralves          #+#    #+#             */
/*   Updated: 2022/10/30 12:32:57 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/so_long.h"

void	put_sprite(t_vars *vars, void *img, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, img, x, y);
}

void	*choose_sprite(t_vars *vars, char **map, t_count c)
{
	if (map[c.row][c.collumn] == PLAYER)
		return (vars->sprite.cavalinho.img);
	if (map[c.row][c.collumn] == WALL)
		return (vars->sprite.wall.img);
	if (map[c.row][c.collumn] == COLLECTIBLE)
		return (vars->sprite.item.img);
	if (map[c.row][c.collumn] == ENDPOINT)
		return (vars->sprite.endpoint.img);
	if (map[c.row][c.collumn] == EMPTY)
		return (vars->sprite.floor.img);
	if (map[c.row][c.collumn] == TEMP1)
		return (vars->sprite.temp1.img);
	return (NULL);
	//if error
}

void	sprite_place(t_vars *vars, char **map)
{
	t_count	c;
	void	*sprite;

	c.row = 0;
	c.collumn = 0;
	while (map[c.row])
	{
		c.collumn = 0;
		while (map[c.row][c.collumn])
		{
			sprite = choose_sprite(vars, map, c);
			put_sprite(vars, sprite, c.collumn * PIXEL_SIZE, c.row * PIXEL_SIZE);
			c.collumn ++;
		}
		c.row ++;
	}
}
	
void	load_xpm(t_vars *vars, t_imagem *img, void *sprite)
{
	int		width;
	int		height;

	img->img = mlx_xpm_file_to_image(vars->mlx, sprite, &width, &height);
	if (img->img == NULL)
		ft_printf("Error\nImage not loaded\n");
}

void	load_img(t_vars *vars)
{
	load_xpm(vars, &(vars->sprite.cavalinho), SPRITE_CHAR);
	load_xpm(vars, &(vars->sprite.wall), SPRITE_WALL);
	load_xpm(vars, &(vars->sprite.item), SPRITE_ITEM);
	load_xpm(vars, &(vars->sprite.endpoint), SPRITE_EXIT);
	load_xpm(vars, &(vars->sprite.floor), SPRITE_FLOOR);
	load_xpm(vars, &(vars->sprite.temp1), SPRITE_TEMP1);
}
