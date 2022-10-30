/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:37:58 by feralves          #+#    #+#             */
/*   Updated: 2022/10/29 20:06:28 by feralves         ###   ########.fr       */
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
	//check if null
	vars->win = mlx_new_window(vars->mlx, PIXEL_SIZE * vars->fullmap->width, \
	PIXEL_SIZE * vars->fullmap->height, "so_long");
	//check if null
	ft_printf_array(vars->fullmap->map); //temp
	//vars->img_static = mlx_new_image(vars->mlx, PIXEL_SIZE * vars->fullmap->width, PIXEL_SIZE * vars->fullmap->height);
	load_img(vars);
	sprite_place(vars, vars->fullmap->map);
	mlx_expose_hook(vars->win, &render_game, vars);
	mlx_hook(vars->win, 2, (1L << 0), key_hook, vars);
	mlx_hook(vars->win, 17, (1L << 2), click_hook, vars);
	mlx_loop_hook(vars->mlx, &render_game, vars);
	mlx_loop(vars->mlx);
}
