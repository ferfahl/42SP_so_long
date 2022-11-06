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

#include "../header/so_long_bonus.h"

void	leaving(t_vars *vars, t_count *c, int i, int j)
{
	if (vars->fullmap->collectibles == 0)
	{
		ft_printf("YOU WON!\n\n");
		destroy_and_free(vars);
	}
	vars->fullmap->map[c->r][c->col] = EMPTY;
	vars->fullmap->map[c->r + i][c->col + j] = TEMP1;
	vars->steps++;
}

void	not_leaving(t_vars *vars, t_count *c, int i, int j)
{
	if (vars->fullmap->map[c->r + i][c->col + j] == WALL)
		return ;
	vars->fullmap->map[c->r][c->col] = ENDPOINT;
	vars->fullmap->map[c->r + i][c->col + j] = PLAYER;
	vars->steps++;
}

void	next_move(t_vars *vars, t_count *c, int i, int j)
{
	vars->fullmap->map[c->r][c->col] = EMPTY;
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
	else if (vars->fullmap->map[c.r + i][c.col + j] == EMPTY)
		next_move(vars, &c, i, j);
	else if (vars->fullmap->map[c.r + i][c.col + j] == COLLECTIBLE)
	{
		vars->fullmap->collectibles--;
		next_move(vars, &c, i, j);
	}
	else if (vars->fullmap->map[c.r + i][c.col + j] == ENDPOINT)
		leaving(vars, &c, i, j);
	else if (vars->fullmap->map[c.r + i][c.col + j] == VILLAIN)
	{
		ft_printf("YOU DIED :(\n\n");
		destroy_and_free(vars);
	}
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 119 || keycode == 65362)
		moving(vars, -1, 0);
	if (keycode == 115 || keycode == 65364)
		moving(vars, 1, 0);
	if (keycode == 100 || keycode == 65363)
		moving(vars, 0, 1);
	if (keycode == 97 || keycode == 65361)
		moving(vars, 0, -1);
	if (keycode == 65307)
		destroy_and_free(vars);
	return (0);
}
