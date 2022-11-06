/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_load.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:38:09 by feralves          #+#    #+#             */
/*   Updated: 2022/11/06 12:03:19 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/so_long.h"

void	put_sprite(t_vars *vars, void *img, int x, int y)
{
	mlx_put_image_to_window(vars->mlx, vars->win, img, x, y);
}

void	*choose_sprite(t_vars *vars, char **map, t_count c)
{
	if (map[c.r][c.col] == PLAYER && vars->is_right)
		return (vars->sprite.right_p.img);
	else if (map[c.r][c.col] == PLAYER && !vars->is_right)
		return (vars->sprite.left_p.img);
	if (map[c.r][c.col] == WALL)
		return (vars->sprite.wall.img);
	if (map[c.r][c.col] == COLLECTIBLE)
		return (vars->sprite.item.img);
	if (map[c.r][c.col] == ENDPOINT)
		return (vars->sprite.endpoint.img);
	if (map[c.r][c.col] == EMPTY)
		return (vars->sprite.floor.img);
	if (map[c.r][c.col] == TEMP1)
		return (vars->sprite.temp1.img);
	return (NULL);
}

void	sprite_place(t_vars *vars, char **map)
{
	t_count	c;
	void	*sprite;

	c.r = 0;
	c.col = 0;
	while (map[c.r])
	{
		c.col = 0;
		while (map[c.r][c.col])
		{
			sprite = choose_sprite(vars, map, c);
			put_sprite(vars, sprite, c.col * PIXEL_SIZE, \
			c.r * PIXEL_SIZE);
			c.col ++;
		}
		c.r ++;
	}
}

void	load_xpm(t_vars *vars, t_draw *img, void *sprite)
{
	int		width;
	int		height;

	img->img = mlx_xpm_file_to_image(vars->mlx, sprite, &width, &height);
	if (img->img == NULL)
		if_error("Image not loaded", vars);
}

void	load_img(t_vars *vars)
{
	load_xpm(vars, &(vars->sprite.right_p), SPRITE_CHAR_RIGHT);
	load_xpm(vars, &(vars->sprite.left_p), SPRITE_CHAR_LEFT);
	load_xpm(vars, &(vars->sprite.wall), SPRITE_WALL);
	load_xpm(vars, &(vars->sprite.item), SPRITE_ITEM);
	load_xpm(vars, &(vars->sprite.endpoint), SPRITE_EXIT);
	load_xpm(vars, &(vars->sprite.floor), SPRITE_FLOOR);
	load_xpm(vars, &(vars->sprite.temp1), SPRITE_TEMP1);
}
