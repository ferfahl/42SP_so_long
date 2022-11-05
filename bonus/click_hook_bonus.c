/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   click_hook_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 22:31:32 by feralves          #+#    #+#             */
/*   Updated: 2022/11/05 12:26:42 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

int	click_hook(t_vars *vars)
{
	destroy_and_free(vars);
	return (0);
}
