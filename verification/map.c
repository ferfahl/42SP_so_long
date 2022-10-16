/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:25:37 by feralves          #+#    #+#             */
/*   Updated: 2022/10/16 14:33:38 by feralves         ###   ########.fr       */
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
	int	index;

	index = 0;
	while (fullmap->map[0][index])
	{
		if (fullmap->map[0][index] != WALL)
			return (1);
		index++;
	}
	index = 0;
	while (fullmap->map[fullmap->height - 1][index])
	{
		if (fullmap->map[fullmap->height - 1][index] != WALL)
			return (1);
		index++;
	}
/* 	while (fullmap->map)
	{
		if (fullmap->map[1][0] != WALL)
			return (1);
		if (fullmap->map[fullmap->width - 1][0] != WALL)
			return (1);
	} */
	return (0);
}

int	check_error_2(t_data *fullmap)
{
	if (map_width(fullmap))
		return (ft_printf("Error\n%s\n", ERROR_MAP_3));
	if (check_walls(fullmap))
		return (ft_printf("Error\n%s\n", ERROR_MAP_4));
	return (0);
}

int main(int argc, char **argv)
{
	t_data	fullmap;
	
	if (check_error_1(argc, argv, &fullmap))
		return (1);
	fullmap.map = malloc((fullmap.height + 1)* sizeof(char *));
	write_map(argv[1], &fullmap);
	if (check_error_2(&fullmap))
		return (1);
	ft_printf_array(fullmap.map);
}

/* int	map_format()
{
	t_data	size;
	int file;
	char    *line;
	
	size.height = 1;
	file = open(argv[1], O_RDONLY);
	if (file == -1)
		return (-1);
	line = get_next_line(file);
	if (!line)
		return (-1);
	size.width = ft_strlen_char(line, '\n');
	while (line)
	{
		free(line);
		line = get_next_line(file);
		if (line && ft_strlen_char(line, '\n') != size.width)
		{
			size.height = 0;
			while (line)
			{
				free(line);
				line = get_next_line(file);
			}
			break ;
		}
		else if (line && ft_strlen(line))
			size.height++;
	}
	ft_printf("%d\n", size.height);
	return (size.height);
} */


//read a file (if not file)-> ERROR_MAP_1 
	//check file to turn into map (.ber) -> ERROR_MAP_1 

	//maps verifications
	/*"if any misconfiguration of any kind is encountered in the file, the
	program must exit in a clean way, and return "Error\n" followed by an
	explicit error message of your choice." */
 // ft_printf("Error\n %s\n", );

// generate map archive
	//verify all positions
	//Verificar os botões (- e v) para não permitir que o jogo feche


