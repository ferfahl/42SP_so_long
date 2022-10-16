/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:37:58 by feralves          #+#    #+#             */
/*   Updated: 2022/10/16 15:33:29 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/so_long.h"

void	load_sprite(t_vars *vars, void *sprite)
{
	int		width;
	int		height;

	vars->img = mlx_xpm_file_to_image(vars->mlx, sprite, &width, &height);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 250, 250);
}

void	open_game(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 500, 500, "so_long");
	mlx_hook(vars->win, 2, (1L << 0), esc_hook, vars);
	mlx_hook(vars->win, 17, (1L << 2), click_hook, vars);
	load_sprite(vars, SPRITE_WALL);
	mlx_loop(vars->mlx);
}
