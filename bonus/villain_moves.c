/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   villain_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 10:40:44 by feralves          #+#    #+#             */
/*   Updated: 2022/11/06 12:05:46 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long_bonus.h"

void	finding_v(t_count *v, char **map)
{
	v->r = 1;
	v->col = 1;
	while (map[v->r])
	{
		v->col = 1;
		while (map[v->r][v->col])
		{
			if (map[v->r][v->col] == VILLAIN)
				return ;
			v->col++;
		}
		v->r++;
	}
}

void	moving_v(t_vars *vars, int i, int j)
{
	t_count	v;

	finding_v(&v, vars->fullmap->map);
	if (vars->fullmap->map[v.r + i][v.col + j] == EMPTY)
	{
		vars->fullmap->map[v.r][v.col] = EMPTY;
		vars->fullmap->map[v.r + i][v.col + j] = VILLAIN;
	}
	else if (vars->fullmap->map[v.r + i][v.col + j] == PLAYER)
	{
		ft_printf("YOU DIED :(\n\n");
		destroy_and_free(vars);
	}
}

void	villain_moves(t_vars *vars)
{
	struct timeval	time;
	int				random;

	gettimeofday(&time, NULL);
	srand(time.tv_usec);
	random = rand();
	if (random % 4 == 0)
		moving_v(vars, -1, 0);
	else if (random % 4 == 1)
		moving_v(vars, 0, 1);
	else if (random % 4 == 2)
		moving_v(vars, 1, 0);
	else if (random % 4 == 3)
		moving_v(vars, 0, -1);
}
