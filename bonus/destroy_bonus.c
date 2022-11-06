/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:36:19 by feralves          #+#    #+#             */
/*   Updated: 2022/11/06 11:20:03 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

void	destroy_images(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->sprite.player.right1.img);
	mlx_destroy_image(vars->mlx, vars->sprite.player.right2.img);
	mlx_destroy_image(vars->mlx, vars->sprite.player.left1.img);
	mlx_destroy_image(vars->mlx, vars->sprite.player.left2.img);
	mlx_destroy_image(vars->mlx, vars->sprite.villain.right1.img);
	mlx_destroy_image(vars->mlx, vars->sprite.villain.left1.img);
	mlx_destroy_image(vars->mlx, vars->sprite.item.op1.img);
	mlx_destroy_image(vars->mlx, vars->sprite.item.op2.img);
	mlx_destroy_image(vars->mlx, vars->sprite.floor.op1.img);
	mlx_destroy_image(vars->mlx, vars->sprite.floor.op2.img);
	mlx_destroy_image(vars->mlx, vars->sprite.wall.img);
	mlx_destroy_image(vars->mlx, vars->sprite.endpoint.img);
	mlx_destroy_image(vars->mlx, vars->sprite.temp1.img);
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
