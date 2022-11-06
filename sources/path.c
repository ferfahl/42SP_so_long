/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 19:41:39 by feralves          #+#    #+#             */
/*   Updated: 2022/11/06 14:12:38 by feralves         ###   ########.fr       */
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

	c.r = 1;
	while (dupe[c.r])
	{
		c.col = 1;
		while (dupe[c.r][c.col])
		{
			if (dupe[c.r][c.col] == ENDPOINT)
				return (1);
			else if (dupe[c.r][c.col] == COLLECTIBLE)
				return (1);
			c.col++;
		}
		c.r++;
	}
	return (0);
}

void	finding_p(t_count *c, char **dupe)
{
	c->r = 1;
	c->col = 1;
	while (dupe[c->r])
	{
		c->col = 1;
		while (dupe[c->r][c->col])
		{
			if (dupe[c->r][c->col] == PLAYER || \
			dupe[c->r][c->col] == TEMP1)
				return ;
			c->col++;
		}
		c->r++;
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
	if (!dupe)
		return (ft_printf("Error\nMalloc error\n"));
	create_dupe(fullmap->map, dupe);
	finding_p(&c, dupe);
	flood_fill(dupe, c.r, c.col, fullmap);
	if (check_dupe(dupe))
	{
		ft_free_array(dupe);
		return (ft_printf("Error\n%s\n", ERROR_MAP_1));
	}
	ft_free_array(dupe);
	return (0);
}
