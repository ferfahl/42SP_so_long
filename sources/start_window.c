/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:26:12 by feralves          #+#    #+#             */
/*   Updated: 2022/10/30 12:52:18 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/so_long.h"

void	start_window(t_data *fullmap)
{
	t_vars	*vars;

	vars = (t_vars *)ft_calloc(1, sizeof(t_vars));
	if (vars == NULL)
		if_error("Calloc error", vars);
	vars->fullmap = fullmap;
	open_game(vars);
}
