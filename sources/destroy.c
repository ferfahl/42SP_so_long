/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:36:19 by feralves          #+#    #+#             */
/*   Updated: 2022/10/24 15:37:48 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/so_long.h"

void	destroy_and_free(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->sprite.wall.img);
	mlx_destroy_image(vars->mlx, vars->sprite.item.img);
	mlx_destroy_image(vars->mlx, vars->sprite.cavalinho.img);
	mlx_destroy_image(vars->mlx, vars->sprite.endpoint.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	ft_free_array(vars->fullmap->map);
	free(vars);
	exit(0);
}
