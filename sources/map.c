/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:25:37 by feralves          #+#    #+#             */
/*   Updated: 2022/10/16 10:30:49 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	map_format(int map)
{
	int file;
	size_t  width;
	size_t	height;
	char    *line;
	
	height = 1;
	file = open(MAP_ARCH, O_RDONLY);
	line = get_next_line(file);
	width = ft_strlen_char(line, '\n');
	while (line)
	{
		line = get_next_line(file);
		if (line && ft_strlen(line))
			height++;
		if (line && ft_strlen_char(line, '\n') != width)
			ft_printf("Error\n%s\n", ERROR_MAP_3);
	}
	return (height);
}

int main(void)
{
	t_data	fullmap;
	

	if (!map_format)
		ft_printf("Error\n%s\n", ERROR_MAP_3);

}

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


