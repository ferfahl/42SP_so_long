/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_sprites_load_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:38:09 by feralves          #+#    #+#             */
/*   Updated: 2022/11/05 20:21:56 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

void	put_sprite(t_vars *vars, void *img, int x, int y)
{
	char	*peanuts;

	mlx_put_image_to_window(vars->mlx, vars->win, img, x, y);
	mlx_string_put(vars->mlx, vars->win, 10, 10, 0x000000, "Moves: ");
	peanuts = ft_itoa(vars->steps);
	mlx_string_put(vars->mlx, vars->win, 50, 10, 0x000000, peanuts);
	free(peanuts);
}

void	*choose_doll(t_vars *vars, char **map, t_count c, int time)
{
	if (map[c.row][c.collumn] == PLAYER && vars->is_right && time)
		return (vars->sprite.player.right1.img);
	else if (map[c.row][c.collumn] == PLAYER && vars->is_right && !time)
		return (vars->sprite.player.right2.img);
	else if (map[c.row][c.collumn] == PLAYER && !vars->is_right && time)
		return (vars->sprite.player.left1.img);
	else if (map[c.row][c.collumn] == PLAYER && !vars->is_right && !time)
		return (vars->sprite.player.left2.img);
	else if (map[c.row][c.collumn] == VILLAIN && time)
		return (vars->sprite.villain.left1.img);
 	else if (map[c.row][c.collumn] == VILLAIN && !time)
		return (vars->sprite.villain.right1.img);
/*	else if (map[c.row][c.collumn] == VILLAIN && time)
		return (vars->sprite.villain.right2.img);
	else if (map[c.row][c.collumn] == VILLAIN && !time)
		return (vars->sprite.villain.right2.img); */
	return (NULL);
}

void	*choose_sprite(t_vars *vars, char **map, t_count c, int time)
{
	if (map[c.row][c.collumn] == PLAYER)
		return (choose_doll(vars, map, c, time));
	if (map[c.row][c.collumn] == VILLAIN)
		return (choose_doll(vars, map, c, time));
	if (map[c.row][c.collumn] == WALL && time)
		return (vars->sprite.wall.op1.img);
	if (map[c.row][c.collumn] == WALL && !time)
		return (vars->sprite.wall.op2.img);
	if (map[c.row][c.collumn] == COLLECTIBLE && time)
		return (vars->sprite.item.op1.img);
	if (map[c.row][c.collumn] == COLLECTIBLE && !time)
		return (vars->sprite.item.op2.img);
	if (map[c.row][c.collumn] == EMPTY && time)
		return (vars->sprite.floor.op1.img);
	if (map[c.row][c.collumn] == EMPTY && !time)
		return (vars->sprite.floor.op2.img);
	if (map[c.row][c.collumn] == ENDPOINT)
		return (vars->sprite.endpoint.img);
	if (map[c.row][c.collumn] == TEMP1)
		return (vars->sprite.temp1.img);
	return (NULL);
}

void	sprite_place(t_vars *vars, char **map, int time)
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
			sprite = choose_sprite(vars, map, c, time);
			put_sprite(vars, sprite, c.collumn * PIXEL_SIZE, \
			c.row * PIXEL_SIZE);
			c.collumn ++;
		}
		c.row ++;
	}
}
