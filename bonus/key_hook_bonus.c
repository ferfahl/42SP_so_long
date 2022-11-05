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

void	leaving(t_vars *vars)
{
	if (vars->fullmap->collectibles == 0)
	{
		ft_printf("YOU WON!");
		destroy_and_free(vars);
	}
}

void	not_leaving(t_vars *vars, t_count *c, size_t i, size_t j)
{
	if (vars->fullmap->map[c->row + i][c->collumn + j] == WALL)
		return ;
	vars->fullmap->map[c->row][c->collumn] = ENDPOINT;
	vars->fullmap->map[c->row + i][c->collumn + j] = PLAYER;
	vars->steps++;
}

void	next_move(t_vars *vars, t_count *c, size_t i, size_t j)
{
	vars->fullmap->map[c->row][c->collumn] = EMPTY;
	vars->fullmap->map[c->row + i][c->collumn + j] = PLAYER;
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
	if (vars->fullmap->map[c.row][c.collumn] == TEMP1)
		not_leaving(vars, &c, i, j);
	if (vars->fullmap->map[c.row + i][c.collumn + j] == EMPTY)
		next_move(vars, &c, i, j);
	else if (vars->fullmap->map[c.row + i][c.collumn + j] == COLLECTIBLE)
	{
		vars->fullmap->collectibles--;
		next_move(vars, &c, i, j);
	}
	else if (vars->fullmap->map[c.row + i][c.collumn + j] == ENDPOINT)
	{
		leaving(vars);
		vars->fullmap->map[c.row][c.collumn] = EMPTY;
		vars->fullmap->map[c.row + i][c.collumn + j] = TEMP1;
		vars->steps++;
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
