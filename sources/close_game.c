/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:31:32 by feralves          #+#    #+#             */
/*   Updated: 2022/10/16 15:32:14 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/so_long.h"

int	esc_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		destroy_and_free(vars);
		exit (0);
	}
	ft_printf("%d\n", keycode);
	return (0);
}

int	click_hook(t_vars *vars)
{
	destroy_and_free(vars);
	exit (0);
	return (0);
}
