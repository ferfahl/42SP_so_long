/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:25:37 by feralves          #+#    #+#             */
/*   Updated: 2022/10/16 13:42:25 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	map_height(char *file)
{
	int	height;
	int fd;
	char    *line;
	
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

int check_errors(int argc, char **argv, t_data *fullmap)
{
	if (argc != 2)
		return (ft_printf("Error\n%s\n", ERROR_ARG_1)); //ok
	if (check_ber(argv[1] + (ft_strlen(argv[1]) - 4)))
		return (ft_printf("Error\n%s\n", ERROR_ARG_2)); //ok
	fullmap->height = map_height(argv[1]);
	if (!fullmap->height)
		return (ft_printf("Error\n%s\n", ERROR_MAP_2));
	if (fullmap->height == -1)
		return (ft_printf("Error\n%s\n", ERROR_ARG_3));
	return (0);
}

int main(int argc, char **argv)
{
	t_data	fullmap;
	
	if (check_errors(argc, argv, &fullmap))
		return (1);
	fullmap.map = malloc((fullmap.height + 1)* sizeof(char *));
	write_map(argv[1], &fullmap);
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


