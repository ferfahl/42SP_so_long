/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feralves <feralves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:02:51 by feralves          #+#    #+#             */
/*   Updated: 2022/10/17 14:12:02 by feralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

//Headers
# include "so_long.h"
# include "libs.h"

//Structs
typedef struct s_data
{
	char	**map;
	int		height;
	int		width;
	int		collectibles;
}				t_data;

typedef struct s_count
{
	int	row;
	int	collumn;
	int	player;
	int	endpoint;
	int	index;
}				t_count;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	t_data	*fullmap;
}				t_vars;

//Definitions paths
# define SPRITE_WALL "./assets/sprites/wall.xpm"
# define SPRITE_CHAR "./assets/sprites/char.xpm"
# define SPRITE_COLLECTIBLE "./assets/sprites/collectible.xpm"
# define MAP_ARCH "./assets/maps/test.ber"

//Definitions
# define PIXEL_SIZE 32
# define WALL '1'
# define EMPTY '0'
# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define ENDPOINT 'E'
# define FLOOD 'F'

//Error definitions
# define ERROR_MAP_1 "Invalid path"
# define ERROR_MAP_2 "Empty map"
# define ERROR_MAP_3 "Wrong map format"
# define ERROR_MAP_4 "Where are the walls?"
# define ERROR_MAP_5 "Invalid characters"
# define ERROR_MAP_6 "Wrong number of characters/collectibles"
# define ERROR_MAP_7 //valid dimension [tamanho máximo?]
# define ERROR_ARG_1 "Invalid number of arguments"
# define ERROR_ARG_2 "Invalid extension"
# define ERROR_ARG_3 "File not found"

#endif
