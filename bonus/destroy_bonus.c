/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:36:19 by feralves          #+#    #+#             */
/*   Updated: 2022/11/05 19:05:25 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

void	destroy_images(t_vars *vars)
{
	mlx_destroy_image(vars, vars->sprite.player.right1.img);
	mlx_destroy_image(vars, vars->sprite.player.right2.img);
	mlx_destroy_image(vars, vars->sprite.player.left1.img);
	mlx_destroy_image(vars, vars->sprite.player.left2.img);
	mlx_destroy_image(vars, vars->sprite.villain.right1.img);
	mlx_destroy_image(vars, vars->sprite.villain.right2.img);
	mlx_destroy_image(vars, vars->sprite.villain.left1.img);
	mlx_destroy_image(vars, vars->sprite.villain.left2.img);
	mlx_destroy_image(vars, vars->sprite.wall.op1.img);
	mlx_destroy_image(vars, vars->sprite.wall.op2.img);
	mlx_destroy_image(vars, vars->sprite.item.op1.img);
	mlx_destroy_image(vars, vars->sprite.item.op2.img);
	mlx_destroy_image(vars, vars->sprite.floor.op1.img);
	mlx_destroy_image(vars, vars->sprite.floor.op1.img);
	mlx_destroy_image(vars, vars->sprite.endpoint.img);
	mlx_destroy_image(vars, vars->sprite.temp1.img);
}

void	destroy_and_free(t_vars *vars)
{
	destroy_images(vars);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	ft_free_array(vars->fullmap->map);
	free(vars);
	exit(0);
}

void	if_error(char *message, t_vars *vars)
{
	ft_printf("Error\n%s\n", message);
	destroy_and_free(vars);
}
