/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:37:58 by feralves          #+#    #+#             */
/*   Updated: 2022/11/06 13:49:19 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/so_long.h"

int	render_game(t_vars *vars)
{
	sprite_place(vars, vars->fullmap->map);
	return (0);
}

void	open_game(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		if_error("Mlx init error", vars);
	vars->win = mlx_new_window(vars->mlx, PIXEL_SIZE * vars->fullmap->width, \
	PIXEL_SIZE * vars->fullmap->height, "so_long");
	if (vars->win == NULL)
		if_error("Mlx window error", vars);
	load_img(vars);
	sprite_place(vars, vars->fullmap->map);
	mlx_expose_hook(vars->win, &render_game, vars);
	mlx_hook(vars->win, KEY_PRESS_EVENT, (1L << 0), key_hook, vars);
	mlx_hook(vars->win, CLICK_EVENT, (1L << 2), click_hook, vars);
	mlx_loop_hook(vars->mlx, &render_game, vars);
	mlx_loop(vars->mlx);
}
