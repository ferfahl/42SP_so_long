/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_xpm_load.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:15:00 by feralves          #+#    #+#             */
/*   Updated: 2022/11/06 11:20:18 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

void	load_xpm(t_vars *vars, t_draw *img, void *sprite)
{
	int		pixel;

	pixel = 32;
	img->img = mlx_xpm_file_to_image(vars->mlx, sprite, &pixel, &pixel);
	if (img->img == NULL)
		if_error("Image not loaded", vars);
}

void	load_img(t_vars *vars)
{
	load_xpm(vars, &(vars->sprite.player.right1), SPRITE_CHAR_R1);
	load_xpm(vars, &(vars->sprite.player.right2), SPRITE_CHAR_R2);
	load_xpm(vars, &(vars->sprite.player.left1), SPRITE_CHAR_L1);
	load_xpm(vars, &(vars->sprite.player.left2), SPRITE_CHAR_L2);
	load_xpm(vars, &(vars->sprite.villain.right1), SPRITE_V1);
	load_xpm(vars, &(vars->sprite.villain.left1), SPRITE_V2);
	load_xpm(vars, &(vars->sprite.item.op1), SPRITE_I1);
	load_xpm(vars, &(vars->sprite.item.op2), SPRITE_I2);
	load_xpm(vars, &(vars->sprite.floor.op1), SPRITE_F1);
	load_xpm(vars, &(vars->sprite.floor.op2), SPRITE_F2);
	load_xpm(vars, &(vars->sprite.wall), SPRITE_W);
	load_xpm(vars, &(vars->sprite.endpoint), SPRITE_EXIT);
	load_xpm(vars, &(vars->sprite.temp1), SPRITE_T1);
}
