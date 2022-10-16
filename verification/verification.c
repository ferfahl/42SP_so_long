/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:25:37 by feralves          #+#    #+#             */
/*   Updated: 2022/10/16 15:37:10 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	map_height(char *file)
{
	int		height;
	int		fd;
	char	*line;

	height = 1;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	if (!line)
		return (0);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line && ft_strlen(line))
			height++;
	}
	close(fd);
	return (height);
}

void	write_map(char *file, t_data *fullmap)
{
	int	fd;
	int	index;

	index = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return ;
	while (index < fullmap->height)
	{
		fullmap->map[index] = get_next_line(fd);
		fullmap->map[index] = ft_strtrim_mod(fullmap->map[index], "\n");
		index++;
	}
	fullmap->map[index] = NULL;
	close(fd);
}

int	check_ber(char *str)
{
	if (!ft_strncmp(str, ".ber", 5))
		return (0);
	return (1);
}

int	check_error_1(int argc, char **argv, t_data *fullmap)
{
	if (argc != 2)
		return (ft_printf("Error\n%s\n", ERROR_ARG_1));
	if (check_ber(argv[1] + (ft_strlen(argv[1]) - 4)))
		return (ft_printf("Error\n%s\n", ERROR_ARG_2));
	fullmap->height = map_height(argv[1]);
	if (!fullmap->height)
		return (ft_printf("Error\n%s\n", ERROR_MAP_2));
	if (fullmap->height == -1)
		return (ft_printf("Error\n%s\n", ERROR_ARG_3));
	return (0);
}
