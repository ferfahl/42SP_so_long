/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:26:12 by feralves          #+#    #+#             */
/*   Updated: 2022/10/16 21:13:16 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/so_long.h"

void	attribute(t_vars *vars)
{
	vars->mlx = NULL;
	vars->win = NULL;
	vars->img = NULL;
}

void	start_window(t_data *fullmap)
{
	t_vars	*vars;

	vars = (t_vars *)malloc(sizeof(t_vars));
	vars->fullmap = fullmap;
	attribute(vars);
	open_game(vars);
}
