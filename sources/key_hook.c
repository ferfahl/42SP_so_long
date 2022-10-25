/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:22:37 by feralves          #+#    #+#             */
/*   Updated: 2022/10/25 10:13:18 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/so_long.h"

void    move_up(t_vars *vars)
{
    (void)vars;
    ft_printf("Up\n");
}

void    move_down(t_vars *vars)
{
    (void)vars;
    ft_printf("Down\n");
}

void    move_left(t_vars *vars)
{
    (void)vars;
    ft_printf("Left\n");
}

void    move_right(t_vars *vars)
{
    (void)vars;
    ft_printf("Right\n");
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 119 || keycode == 65362)
		move_up(vars);
    if (keycode == 115 || keycode == 65364)
		move_down(vars);
    if (keycode == 100 || keycode == 65363)
		move_right(vars);
    if (keycode == 97 || keycode == 65361)
		move_left(vars);
    if (keycode == 65307)
		destroy_and_free(vars);
	ft_printf("%d\n", keycode);
	return (0);
}
