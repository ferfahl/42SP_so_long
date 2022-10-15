/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:37:58 by feralves          #+#    #+#             */
/*   Updated: 2022/10/14 22:38:50 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/so_long.h"

void	load_sprite(t_vars *vars)
{
	int		img_width = 32;
	int		img_height = 32;

	vars->img = mlx_xpm_file_to_image(vars->mlx, SPRITE_WALL, &img_width, &img_height);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 250, 250);
}

void	open_game(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 500, 500, "so_long");
	mlx_hook(vars->win, 2, 1L<<0, esc_hook, vars);
	mlx_hook(vars->win, 17, 1L<<2, click_hook, vars);
	load_sprite(vars);
	mlx_loop(vars->mlx);
}
