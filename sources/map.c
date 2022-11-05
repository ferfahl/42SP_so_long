/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:25:37 by feralves          #+#    #+#             */
/*   Updated: 2022/10/16 20:08:54 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	map_width(t_data *fullmap)
{
	int	index;

	index = 1;
	fullmap->width = ft_strlen(fullmap->map[0]);
	while (index < fullmap->height)
	{
		if ((int)ft_strlen(fullmap->map[index]) != fullmap->width)
			return (1);
		index++;
	}
	return (0);
}

int	check_walls(t_data *fullmap)
{
	int	row;
	int	collumn;

	row = 0;
	while (fullmap->map[row])
	{
		collumn = 0;
		while (fullmap->map[row][collumn])
		{
			if (row == 0 || row == fullmap->height - 1)
			{
				if (fullmap->map[row][collumn] != WALL)
					return (1);
			}
			else if (collumn == 0 || collumn == fullmap->width - 1)
			{
				if (fullmap->map[row][collumn] != WALL)
					return (1);
			}
			collumn++;
		}
		row++;
	}
	return (0);
}

int	check_extras(t_data *fullmap)
{
	t_count	c;

	c.player = 0;
	c.endpoint = 0;
	fullmap->collectibles = 0;
	c.row = 0;
	while (fullmap->map[++c.row])
	{
		c.collumn = 0;
		while (fullmap->map[c.row][++c.collumn])
		{
			if (fullmap->map[c.row][c.collumn] == PLAYER)
				c.player++;
			else if (fullmap->map[c.row][c.collumn] == ENDPOINT)
				c.endpoint++;
			else if (fullmap->map[c.row][c.collumn] == COLLECTIBLE)
				fullmap->collectibles++;
			else if (fullmap->map[c.row][c.collumn] != EMPTY
				&& fullmap->map[c.row][c.collumn] != WALL)
				return (1);
		}
	}
	if (!fullmap->collectibles || c.player != 1 || c.endpoint != 1)
		return (2);
	return (0);
}

int	check_error_2(t_data *fullmap)
{
	int	check;

	if (map_width(fullmap))
		return (ft_printf("Error\n%s\n", ERROR_MAP_3));
	if (check_walls(fullmap))
		return (ft_printf("Error\n%s\n", ERROR_MAP_4));
	check = check_extras(fullmap);
	if (check == 1)
		return (ft_printf("Error\n%s\n", ERROR_MAP_5));
	if (check == 2)
		return (ft_printf("Error\n%s\n", ERROR_MAP_6));
	return (0);
}
