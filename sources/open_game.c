/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:37:58 by feralves          #+#    #+#             */
/*   Updated: 2022/10/25 10:38:58 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/so_long.h"

void	open_game(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, PIXEL_SIZE * vars->fullmap->width, \
	PIXEL_SIZE * vars->fullmap->height, "so_long");
	mlx_hook(vars->win, 2, (1L << 0), key_hook, vars);
	mlx_hook(vars->win, 17, (1L << 2), click_hook, vars);
	load_img(vars);
	ft_printf_array(vars->fullmap->map);
	sprite_place(vars, vars->fullmap->map);
	mlx_loop(vars->mlx);
}
