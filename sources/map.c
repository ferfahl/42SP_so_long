/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:25:37 by feralves          #+#    #+#             */
/*   Updated: 2022/10/16 12:42:45 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	map_height()
{
	int	height;
	int file;
	char    *line;
	
	height = 1;
	file = open(MAP_ARCH, O_RDONLY);
	if (file == -1)
		return (-1);
	line = get_next_line(file);
	if (!line)
		return (0);
	while (line)
	{
		free(line);
		line = get_next_line(file);
		if (line && ft_strlen(line))
			height++;
	}
	close(file);
	return (height);
}

void	write_map(t_data *fullmap)
{
	int	file;
	int	index;
	
	index = 0;
	file = open(MAP_ARCH, O_RDONLY);
	if (file == -1)
		return ;
	while (index < fullmap->height)
	{
		fullmap->map[index] = get_next_line(file);
		fullmap->map[index] = ft_strtrim_mod(fullmap->map[index], "\n");
		index++;
	}
	fullmap->map[index] = NULL;
	close(file);
}


int main(void)
{
	t_data	fullmap;
	
	fullmap.height = map_height();
	if (!fullmap.height)
		return (ft_printf("Error\n%s\n", ERROR_MAP_2));
	else if (fullmap.height == -1)
		return (ft_printf("Error\n%s\n", ERROR_MAP_1));
//	ft_printf("%d\n", fullmap.height);
	fullmap.map = malloc((fullmap.height + 1)* sizeof(char *));
	write_map(&fullmap);
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


