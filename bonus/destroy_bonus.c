/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:36:19 by feralves          #+#    #+#             */
/*   Updated: 2022/11/05 12:26:32 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

void	destroy_images(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->sprite.wall.img);
	mlx_destroy_image(vars->mlx, vars->sprite.item.img);
	mlx_destroy_image(vars->mlx, vars->sprite.right_p.img);
	mlx_destroy_image(vars->mlx, vars->sprite.left_p.img);
	mlx_destroy_image(vars->mlx, vars->sprite.endpoint.img);
	mlx_destroy_image(vars->mlx, vars->sprite.floor.img);
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
