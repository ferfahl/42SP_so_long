/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:22:37 by feralves          #+#    #+#             */
/*   Updated: 2022/10/25 09:44:37 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		destroy_and_free(vars);
	}
	ft_printf("%d\n", keycode);
	return (0);
}
