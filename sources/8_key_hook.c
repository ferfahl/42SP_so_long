/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   key_hook.c										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: feralves <feralves@student.42sp.org.br>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/10/24 14:22:37 by feralves		  #+#	#+#			 */
/*   Updated: 2022/10/25 10:40:27 by feralves		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "./header/so_long.h"

void	leaving(t_vars *vars)
{
	if (vars->fullmap->collectibles == 0)
	{
		ft_printf("YOU WON!\n\n");
		destroy_and_free(vars);
	}
}

void	next_move(t_vars *vars, t_count *c, size_t i, size_t j)
{
	vars->fullmap->map[c->r][c->col] = EMPTY;
	vars->fullmap->map[c->r + i][c->col + j] = PLAYER;
	vars->steps++;
}

void	not_leaving(t_vars *vars, t_count *c, size_t i, size_t j)
{
	if (vars->fullmap->map[c->r + i][c->col + j] == WALL)
		return ;
	else if (vars->fullmap->map[c->r + i][c->col + j] == COLLECTIBLE)
	{
		vars->fullmap->collectibles--;
		next_move(vars, c, i, j);
	}
	vars->fullmap->map[c->r][c->col] = ENDPOINT;
	vars->fullmap->map[c->r + i][c->col + j] = PLAYER;
	vars->steps++;
}

void	moving(t_vars *vars, int i, int j)
{
	t_count	c;

	if (j == 1)
		vars->is_right = 1;
	else if (j == -1)
		vars->is_right = 0;
	finding_p(&c, vars->fullmap->map);
	if (vars->fullmap->map[c.r][c.col] == TEMP1)
		not_leaving(vars, &c, i, j);
	if (vars->fullmap->map[c.r + i][c.col + j] == EMPTY)
		next_move(vars, &c, i, j);
	else if (vars->fullmap->map[c.r + i][c.col + j] == COLLECTIBLE)
	{
		vars->fullmap->collectibles--;
		next_move(vars, &c, i, j);
	}
	else if (vars->fullmap->map[c.r + i][c.col + j] == ENDPOINT)
	{
		leaving(vars);
		vars->fullmap->map[c.r][c.col] = EMPTY;
		vars->fullmap->map[c.r + i][c.col + j] = TEMP1;
		vars->steps++;
	}
	ft_printf("Moves: %d\n", vars->steps);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == UP || keycode == W_KEY)
		moving(vars, -1, 0);
	if (keycode == DOWN || keycode == S_KEY)
		moving(vars, 1, 0);
	if (keycode == RIGHT || keycode == D_KEY)
		moving(vars, 0, 1);
	if (keycode == LEFT || keycode == A_KEY)
		moving(vars, 0, -1);
	if (keycode == ESC)
		destroy_and_free(vars);
	return (0);
}
