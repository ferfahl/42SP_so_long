/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 19:41:39 by feralves          #+#    #+#             */
/*   Updated: 2022/10/16 21:07:56 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	create_dupe(char **map, char **dupe)
{
	int	index;

	index = 0;
	while (map[index])
	{
		dupe[index] = ft_strdup(map[index]);
		index++;
	}
	dupe[index] = NULL;
}

int	check_dupe(char **dupe)
{
	t_count	c;

	c.row = 1;
	while (dupe[c.row])
	{
		c.collumn = 1;
		while (dupe[c.row][c.collumn])
		{
			if (dupe[c.row][c.collumn] == ENDPOINT)
				return (1);
			else if (dupe[c.row][c.collumn] == COLLECTIBLE)
				return (1);
			c.collumn++;
		}
		c.row++;
	}
	return (0);
}

void	finding_p(t_count *c, char **dupe)
{
	c->row = 1;
	c->collumn = 1;
	while (dupe[c->row])
	{
		c->collumn = 1;
		while (dupe[c->row][c->collumn])
		{
			if (dupe[c->row][c->collumn] == PLAYER)
				return ;
			c->collumn++;
		}
		c->row++;
	}
}

void	flood_fill(char **dupe, int row, int collumn, t_data *fullmap)
{
	if (row >= fullmap->height || collumn >= fullmap->width
		|| dupe[row][collumn] == WALL || dupe[row][collumn] == FLOOD)
		return ;
	dupe[row][collumn] = FLOOD;
	flood_fill(dupe, row + 1, collumn, fullmap);
	flood_fill(dupe, row - 1, collumn, fullmap);
	flood_fill(dupe, row, collumn + 1, fullmap);
	flood_fill(dupe, row, collumn - 1, fullmap);
}

int	check_path(t_data *fullmap)
{
	char	**dupe;
	t_count	c;

	dupe = malloc((fullmap->height + 1) * sizeof(char *));
	create_dupe(fullmap->map, dupe);
	finding_p(&c, dupe);
	flood_fill(dupe, c.row, c.collumn, fullmap);
	if (check_dupe(dupe))
		return (ft_printf("Error\n%s\n", ERROR_MAP_1));
	ft_free_array(dupe);
	return (0);
}
