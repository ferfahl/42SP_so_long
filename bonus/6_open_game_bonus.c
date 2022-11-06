/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_open_game_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:37:58 by feralves          #+#    #+#             */
/*   Updated: 2022/11/06 11:24:06 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

int	render_game(t_vars *vars)
{
	struct timeval	time01;
	int				time02;

	gettimeofday(&time01, NULL);
	if (time01.tv_usec > 500000)
		time02 = 1;
	else
		time02 = 0;
	if (time01.tv_sec % 2 == 1 && vars->moved == 0)
	{
		vars->moved = 1;
		villain_moves(vars);
	}
	if (time01.tv_sec % 2 == 0)
		vars->moved = 0;
	sprite_place(vars, vars->fullmap->map, time02);
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
	sprite_place(vars, vars->fullmap->map, 0);
	mlx_expose_hook(vars->win, &render_game, vars);
	mlx_hook(vars->win, 2, (1L << 0), key_hook, vars);
	mlx_hook(vars->win, 17, (1L << 2), click_hook, vars);
	mlx_loop_hook(vars->mlx, &render_game, vars);
	mlx_loop(vars->mlx);
}
